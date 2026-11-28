"""Exercise the original ClassInfo receiver with basic CoreFoundation bindings."""

from original_cache_oracle import OriginalCacheOracle
from unicorn import UC_HOOK_CODE

AU, ENGINE, ENGINE_TABLE = 0x520000, 0x520200, 0x520600
POOL, POOL_TABLE = 0x521000, 0x521200
DICTIONARY, VERSION, TYPE, SUBTYPE, MANUFACTURER, CF_DATA = range(0x522000, 0x522600, 0x100)
RAW, GN_DATA, LOAD, STATUS = 0x540000, 0x530000, 0x500920, 0x500930
IDENTITY = (0x61756d75, 0x454c534b, 0x55424552)


class ClassInfoOracle(OriginalCacheOracle):
    def __init__(self, binary):
        super().__init__(binary)
        fields = {0x36c570: VERSION, 0x36c56c: TYPE, 0x36c568: SUBTYPE, 0x36c564: MANUFACTURER,
                  0x36c560: CF_DATA, 0x36c55c: 0}
        self.keys = {self.word(address): value for address, value in fields.items()}
        assert len(self.keys) == len(fields)
        self.put(AU + 0x13c, ENGINE)
        self.put(ENGINE, ENGINE_TABLE)
        self.put(ENGINE_TABLE + 0x2e0, LOAD)
        self.put(ENGINE_TABLE + 0x350, STATUS)
        self.put(POOL, POOL_TABLE)
        self.put(POOL_TABLE + 0x44, STATUS)
        self.import_handlers.update({
            '_CFGetTypeID': self.get_type, '_CFDictionaryGetTypeID': self.dictionary_type,
            '_GetComponentInfo': self.component_info, '_CFDictionaryGetValue': self.get_value,
            '_CFNumberGetValue': self.get_number, '__Znwm': self.allocate,
            '_CFDataGetLength': self.data_size, '_CFDataGetBytePtr': self.data_bytes,
            '_CFDictionaryGetValueIfPresent': self.key_not_present,
        })
        for address, fn in {
                0x4210: self.no_result, 0x5f2c: self.no_result, 0x1e688: self.no_result,
                0x2dfa6: self.identity, 0x2803a: self.make_data, LOAD: self.load, STATUS: self.no_result,
        }.items():
            self.uc.hook_add(UC_HOOK_CODE, fn, begin=address, end=address)

    def no_result(self, *unused):
        self.finish()

    def identity(self, *unused):
        obj, = self.arguments(1)
        self.finish(obj)

    def get_type(self):
        obj, = self.arguments(1)
        assert obj == DICTIONARY
        self.finish(1)

    def dictionary_type(self):
        self.finish(1)

    def component_info(self):
        _, description = self.arguments(2)
        self.put(description, *IDENTITY, 0, 0)
        self.finish()

    def get_value(self):
        obj, key = self.arguments(2)
        assert obj == DICTIONARY
        self.finish(self.keys[key])

    def key_not_present(self):
        obj, _, _ = self.arguments(3)
        assert obj == DICTIONARY
        self.finish()

    def get_number(self):
        obj, type_, destination = self.arguments(3)
        assert type_ == 3
        self.put(destination, self.input_values[obj])
        self.finish(1)

    def allocate(self):
        size, = self.arguments(1)
        assert size == 0x14
        self.finish(POOL)

    def data_size(self):
        obj, = self.arguments(1)
        assert obj == CF_DATA
        self.finish(len(self.raw))

    def data_bytes(self):
        obj, = self.arguments(1)
        assert obj == CF_DATA
        self.finish(RAW)

    def make_data(self, *unused):
        data, count = self.arguments(2)
        assert data == RAW and count == len(self.raw)
        self.put(GN_DATA, data, count)
        self.finish(GN_DATA)

    def load(self, *unused):
        receiver, data = self.arguments(2)
        assert receiver == ENGINE and data == GN_DATA
        self.payload = bytes(self.uc.mem_read(self.word(data), self.word(data + 4)))
        self.finish()

    def run(self, raw, version=0, identity=IDENTITY):
        self.input_values = dict(zip((VERSION, TYPE, SUBTYPE, MANUFACTURER), (version, *identity)))
        self.raw, self.payload = raw, None
        self.uc.mem_write(RAW, raw)
        status = self.call(0x5b64, AU, DICTIONARY)
        return status, self.payload
