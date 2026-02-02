#ifndef GLOWSHROOM_H
#define GLOWSHROOM_H

#include "config.h"
#include "render.h"
#include "template.h"

/* A renderable glowing mushroom instance */
typedef struct
{
        const template_t* tpl;
        color_t color;
} glowshroom_t;

/* Create a glowshroom from config (species + color) */
glowshroom_t glowshroom_create(config_t *cfg);

/* Render glowshroom to buffer with glow effect */
void glowshroom_render(buffer_t *buf, glowshroom_t *gshroom);

#endif
