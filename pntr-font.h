#ifndef PNTR_H__
#define PNTR_H__

#include <stdint.h>  // uint32_t

#ifndef PNTR_API
#define PNTR_API
#endif

#ifdef PNTR_IMPLEMENTATION
#ifndef PNTR_IMPLEMENTATION_ONCE
#define PNTR_IMPLEMENTATION_ONCE

#ifdef __cplusplus
extern "C" {
#endif

// load a bmfont from a file
PNTR_API pntr_font* pntr_load_font(const char* fileName, const char* characters);

// load a bmfont from memory-array
PNTR_API pntr_font* pntr_load_font_from_memory(const unsigned char* fileData, unsigned int dataSize, const char* characters);

#endif  // PNTR_H__

PNTR_API pntr_font* pntr_load_font(const char* fileName, const char* characters) {
  // TODO
  return pntr_load_default_font();
}

PNTR_API pntr_font* pntr_load_font_from_memory(const unsigned char* fileData, unsigned int dataSize, const char* characters) {
  // TODO
  return pntr_load_default_font();
}

#ifdef __cplusplus
}
#endif

#endif  // PNTR_IMPLEMENTATION_ONCE
#endif  // PNTR_IMPLEMENTATION