#ifndef TEMPL_H
#define TEMPL_H

#include "render.h"

/* ASCII art template for a mushroom species */
typedef struct
{
        const char *name;       /* Species identifier */
        const char **lines;     /* ASCII art lines (NULL-terminated) */
        const char *glow_chars; /* Characters that emit glow */
        color_t color;          /* Default glow color */
} template_t;

/* Look up template by name. Returns NULL if not found. */
const template_t *template_get(const char *name);

/* Get dimensions of template's ASCII art */
void template_size(const template_t *tpl, int *w, int *h);

/* Returns 1 if species name exists, 0 otherwise */
int template_exists(const char *name);

#endif
