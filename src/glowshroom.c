#include "glowshroom.h"
#include "render.h"
#include "template.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

glowshroom_t glowshroom_create(config_t *cfg)
{
        assert(cfg!=NULL && "Invalid argument");
        glowshroom_t gshroom;
        gshroom.color = cfg->color;
        gshroom.tpl = template_get(cfg->species);
        return gshroom;
}

void glowshroom_render(buffer_t *buf, glowshroom_t *gshroom)
{
        assert(buf!=NULL && "Invalid argument buffer");
        assert(gshroom!=NULL && "Invalid argument ghroom");

        const template_t *tpl = gshroom->tpl;
        color_t final_color = (color_is_zero(gshroom->color) ? tpl->color : gshroom->color);


        for (size_t y = 0; y < (size_t)buf->height; y++) {
                for (size_t x = 0; x < (size_t)buf->width; x++) {
                        char ch = tpl->lines[y][x];
                        if (ch == ' ') continue;

                        int idx = y * buf->width + x;
                        buf->cells[idx].ch = ch;

                        if (strchr(tpl->glow_chars, ch)) {
                                buf->cells[idx].fg = final_color;
                                buf->cells[idx].bg = color_dim(final_color, 0.3);
                        } else {
                                buf->cells[idx].fg = (color_t){ 180, 180, 180};
                        }
                }
        }
}
