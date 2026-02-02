#ifndef TEMPL_H
#define TEMPL_H

#include "render.h"

typedef struct
{
        const char *name;
        const char **lines;
        const char *glow_chars;
        color_t color;
} template_t;

const template_t *template_get(const char *name);
void template_size(const template_t *tpl, int *w, int *h);

#endif
