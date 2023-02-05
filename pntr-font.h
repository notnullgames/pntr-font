#ifndef PNTR_FONT_H__
#define PNTR_FONT_H__

// TODO: eventually this will be inlined
#include <schrift.h>

#ifndef PNTR_FONT_API
#define PNTR_FONT_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

// TODO: work out fontSize

// convert a schrift font to pntr font
PNTR_API pntr_font* sft_to_pntr(SFT_Font* fontIn);

// load a font from a file
PNTR_API pntr_font* pntr_load_font(const char* fileName);

// load a font from memory-array
PNTR_API pntr_font* pntr_load_font_from_memory(const unsigned char* fileData, unsigned int dataSize);

#endif  // PNTR_FONT_H__

#ifdef PNTR_FONT_IMPLEMENTATION
#ifndef PNTR_FONT_IMPLEMENTATION_ONCE
#define PNTR_FONT_IMPLEMENTATION_ONCE

PNTR_API pntr_font* sft_to_pntr(SFT_Font* fontIn) {
  // TODO
  return pntr_load_default_font();
}

PNTR_API pntr_font* pntr_load_font(const char* fileName) {
  if (fileName == NULL) {
    return pntr_set_error("pntr_load_font() requires a valid fileName");
  }

  SFT_Font* fontIn = sft_loadfile(fileName);
  pntr_font* fontOut = sft_to_pntr(fontIn);
  sft_freefont(fontIn);
  return fontOut;
}

PNTR_API pntr_font* pntr_load_font_from_memory(const unsigned char* fileData, unsigned int dataSize) {
  SFT_Font* fontIn = sft_loadmem(fileData, dataSize);
  pntr_font* fontOut = sft_to_pntr(fontIn);
  sft_freefont(fontIn);
  return fontOut;
}

#ifdef __cplusplus
}
#endif

#endif  // PNTR_FONT_IMPLEMENTATION
#endif  // PNTR_FONT_IMPLEMENTATION_ONCE
