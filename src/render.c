#include "render.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANSI_RESET      "\e[0m"
#define ANSI_FG_DEFAULT "\e[39m"
#define ANSI_BG_DEFAULT "\e[49m"

#define ANSI_FG_RGB     "\e[38;2;%d;%d;%dm"
#define ANSI_BG_RGB     "\e[48;2;%d;%d;%dm"

static int color_is_zero(color_t c)
{
        return c.r == 0 && c.g == 0 && c.b == 0;
}

buffer_t* buffer_create(int w, int h)
{
        buffer_t* buf = malloc(sizeof(buffer_t));
        if (buf) {
                buf->width = w;
                buf->height = h;
                buf->cells = malloc(w * h * sizeof(cell_t));
                if (!buf->cells) {
                        buffer_destroy(buf);
                        fprintf(stderr, "Failed to allocate buffer");
                        exit(EXIT_FAILURE);
                }
                memset(buf->cells, 0, w * h * sizeof(cell_t));
        }
        return buf;
}

void buffer_render(buffer_t *buf)
{
        for (size_t y = 0; y < buf->height; y++) {
                for (size_t x = 0; x < buf->width; x++) {
                        cell_t cell = buf->cells[y * buf->width + x];

                        if (color_is_zero(cell.bg)) {
                                printf(ANSI_BG_DEFAULT);
                        } else {
                                printf(ANSI_BG_RGB, cell.bg.r, cell.bg.g, cell.bg.b);
                        }

                        if (color_is_zero(cell.fg)) {
                                printf(ANSI_FG_DEFAULT);
                        } else {
                                printf(ANSI_FG_RGB, cell.fg.r, cell.fg.g, cell.fg.b);
                        }

                        putchar(cell.ch ? cell.ch : ' ');
                }
                printf(ANSI_RESET);
                putchar('\n');
        }
}

void buffer_destroy(buffer_t *buf)
{
        if (buf) {
                if (buf->cells) {
                        free(buf->cells);
                }
                free(buf);
        }
}
