#ifndef CONFIG_H
#define CONFIG_H

#include "render.h"

typedef struct {
        const char *species;
        color_t color;
} config_t;

config_t parse_args(int argc, char *argv[]);

#endif
