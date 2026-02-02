#ifndef RENDER_H
#define RENDER_H

#include <stdint.h>

/* RGB color value */
typedef struct
{
        uint8_t r, g, b;
} color_t;

/* Single terminal cell with character and colors */
typedef struct
{
        char ch;
        color_t fg;
        color_t bg;
} cell_t;

/* 2D grid of cells for terminal output */
typedef struct
{
        cell_t *cells;
        int width, height;
} buffer_t;

/* Allocate a new buffer. Abort programm while failure */
buffer_t* buffer_create(int w, int h);

/* Print buffer contents to stdout using ANSI escape codes */
void buffer_render(buffer_t* buf);

/* Free buffer memory */
void buffer_destroy(buffer_t* buf);

/* Returns 1 if color is black (0,0,0) */
int color_is_zero(color_t c);

/* Convert hex string (e.g. "FF00FF") to RGB */
color_t hex_to_rgb(const char *hex);

/* Dim a color by factor (0.0 = black, 1.0 = unchanged) */
color_t color_dim(color_t c, float factor);

#endif
