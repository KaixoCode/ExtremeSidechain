
// ------------------------------------------------

#ifdef __cplusplus 
// ^^ For some reason updating to new JUCE tries to compile this PCH 
//    as C somehow somewhere. My guess is JUCE added some C code and
//    since this is a PCH file it tries to include it there as well?
//    So just exclude the contents if this isn't C++, because it
//    fails to build.

// ------------------------------------------------

#pragma once

// ------------------------------------------------

#include <cstddef>

// ------------------------------------------------

#endif

// ------------------------------------------------
