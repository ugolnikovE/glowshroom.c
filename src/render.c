#include "render.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANSI_RESET      "\033[0m"
#define ANSI_FG_DEFAULT "\033[39m"
#define ANSI_BG_DEFAULT "\033[49m"

#define ANSI_FG_RGB     "\033[38;2;%d;%d;%dm"
#define ANSI_BG_RGB     "\033[48;2;%d;%d;%dm"

int color_is_zero(color_t c)
{
        return c.r == 0 && c.g == 0 && c.b == 0;
}

color_t hex_to_rgb(const char* hex)
{
        int r, g, b;
        if (hex[0] == '#') hex++;
        sscanf(hex, "%02x%02x%02x", &r, &g, &b);
        return (color_t){ r, g, b};
}

color_t color_dim(color_t c, float factor)
{
        return (color_t){c.r * factor, c.g * factor, c.b * factor};
}

buffer_t* buffer_create(int w, int h)
{
        buffer_t* buf = malloc(sizeof(buffer_t));
        if (!buf) {
                fprintf(stderr, "Failed to allocate buffer\n");
                exit(EXIT_FAILURE);
        }

        buf->cells = malloc(w * h * sizeof(cell_t));
        if (!buf->cells) {
                fprintf(stderr, "Failed to allocate cells\n");
                buffer_destroy(buf);
                exit(EXIT_FAILURE);
        }

        buf->width = w;
        buf->height = h;
        memset(buf->cells, 0, w * h * sizeof(cell_t));

        return buf;
}

void buffer_render(buffer_t *buf)
{
        for (size_t y = 0; y < (size_t)buf->height; y++) {
                for (size_t x = 0; x < (size_t)buf->width; x++) {
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
