#ifndef CONFIG_H
#define CONFIG_H

#include "render.h"

/* Runtime configuration from command-line arguments */
typedef struct {
        const char *species;
        color_t color;
} config_t;

/* Parse command-line arguments into config. Exits on error. */
config_t parse_args(int argc, char *argv[]);

#endif
