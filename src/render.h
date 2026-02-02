#ifndef RENDER_H
#define RENDER_H

#include <stdint.h>

typedef struct
{
        uint8_t r, g, b;
} color_t;

typedef struct
{
        char ch;
        color_t fg;
        color_t bg;
} cell_t;

typedef struct
{
        cell_t *cells;
        int width, height;
} buffer_t;


buffer_t* buffer_create(int w, int h);
void buffer_render(buffer_t* buf);
void buffer_destroy(buffer_t* buf);

#endif
