#ifndef PNTR_FONT_H__
#define PNTR_FONT_H__

#include <stdint.h>  // uint32_t

#ifndef PNTR_API
#define PNTR_API
#endif

#ifdef __cplusplus
extern "C" {

#endif

// load a bmfont from a file
PNTR_API pntr_font* pntr_load_font(const char* fileName, unsigned fontSize);

// load a bmfont from memory-array
PNTR_API pntr_font* pntr_load_font_from_memory(const unsigned char* fileData, unsigned int dataSize, unsigned fontSize);

#endif  // PNTR_FONT_H__

#ifdef PNTR_FONT_IMPLEMENTATION
#ifndef PNTR_FONT_IMPLEMENTATION_ONCE
#define PNTR_FONT_IMPLEMENTATION_ONCE

PNTR_API pntr_font* pntr_load_font(const char* fileName, unsigned fontSize) {
  // TODO
  return pntr_load_default_font();
}

PNTR_API pntr_font* pntr_load_font_from_memory(const unsigned char* fileData, unsigned int dataSize, unsigned fontSize) {
  // TODO
  return pntr_load_default_font();
}

#ifdef __cplusplus
}
#endif

#endif  // PNTR_FONT_IMPLEMENTATION
#endif  // PNTR_FONT_IMPLEMENTATION_ONCE
