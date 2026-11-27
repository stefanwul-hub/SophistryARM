#pragma once

#include "OriginalPropertyList.h"

namespace elastik_plist_detail {

std::u16string decode_utf8(std::string_view bytes);
float number_real(std::u16string_view text) noexcept;
ElastikPropertyList parse_xml(std::string_view bytes);

} // namespace elastik_plist_detail
