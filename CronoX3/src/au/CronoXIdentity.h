#pragma once
// Comparison AU identity. The original CrX3 identifier is reserved until validation.
namespace cronox::identity {
inline constexpr unsigned type = 0x61756d75u;
inline constexpr unsigned subtype = 0x43725433u;
inline constexpr unsigned manufacturer = 0x4c696e50u;
inline constexpr unsigned originalSubtype = 0x43725833u;
inline constexpr const char* name = "CronoX 3 ARM Test";
inline constexpr const char* bundleIdentifier = "com.linplug.au.CronoX3.ARMTest";
inline constexpr const char* componentFilename = "CronoX 3 ARM Test.component";
inline constexpr const char* cocoaFactory = "CronoX3ARMTestCocoaFactory";
inline constexpr const char* factory = "CronoX3ARMTestAUFactory";
inline constexpr bool mayReplaceOriginal = false;
} // namespace cronox::identity
