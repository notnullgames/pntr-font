# pntr-font

This provides an API for working with TTF/OTF font files, in the excellant low-level graphics library [pntr](https://github.com/robloach/pntr).

## ttf/otf

This adds a couple functions for working with ttf or otf files:

```c
// load a bmfont from a file
pntr_font* pntr_load_font(const char* fileName, const char* characters);

// load a bmfont from memory-array
pntr_font* pntr_load_font_from_memory(const unsigned char* fileData, unsigned int dataSize, const char* characters);
```

## fonts in general

pntr has some utils you can use with all fonts, including pntr-font:

```c
// generate an image object form some text + font
pntr_image* pntr_gen_image_text(pntr_font* font, const char* text);

// draw some text on an image with a loaded font
void pntr_draw_text(pntr_image* dst, pntr_font* font, const char* text, int posX, int posY);

// unload any font
void pntr_unload_font(pntr_font* font);

// measure text rendered with a font
int pntr_measure_text(pntr_font* font, const char* text);
pntr_vector pntr_measure_text_ex(pntr_font* font, const char* text);

// load the default ttyfont
pntr_font* pntr_load_default_font();
```

## other fonts

pntr already has support for bm & tty fonts. This library is meant to work well with those, and it should all be fairly seemless, for the user-perspective.


### bmfont

These are variable-width, from a 1-char high image, using color lines in between them. I made a [little tool](https://lovefont.surge.sh) to create them from any font you have installed on your system.

```c
// load a bmfont from a file
pntr_font* pntr_load_bmfont(const char* fileName, const char* characters);

// load a bmfont from an existing image object
pntr_font* pntr_load_bmfont_from_image(pntr_image* image, const char* characters);

// load a bmfont from memory-array
pntr_font* pntr_load_bmfont_from_memory(const unsigned char* fileData, unsigned int dataSize, const char* characters);
```

## ttyfont

These are fixed-width fonts, in a grid, from an image.

```c
// load a ttyfont from a file
pntr_font* pntr_load_ttyfont(const char* fileName, int glyphWidth, int glyphHeight, const char* characters);

// load a ttyfont from an existing image object
pntr_font* pntr_load_ttyfont_from_image(pntr_image* image, int glyphWidth, int glyphHeight, const char* characters);

// load a ttyfont from memory-array
pntr_font* pntr_load_ttyfont_from_memory(const unsigned char* fileData, unsigned int dataSize, int glyphWidth, int glyphHeight, const char* characters);
```