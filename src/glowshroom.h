#ifndef GLOWSHROOM_H
#define GLOWSHROOM_H

#include "config.h"
#include "render.h"
#include "template.h"

typedef struct
{
        const template_t* tpl;
        color_t color;
} glowshroom_t;

glowshroom_t glowshroom_create(config_t *cfg);
void glowshroom_render(buffer_t *buf, glowshroom_t *gshroom);

#endif
