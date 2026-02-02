#include "config.h"
#include "render.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void print_help(void)
{
	fprintf(stdout, "glowshroom - Bioluminescent mushrooms in your terminal\n\n");
	fprintf(stdout, "USAGE:\n");
	fprintf(stdout, "  glowshroom [OPTIONS]\n\n");
	fprintf(stdout, "OPTIONS:\n");
	fprintf(stdout, "  -h, --help     Show this help\n");
	fprintf(stdout, "  -c, --color    Set mushroom color (hex, e.g. #ff00ff)\n");
}

static void print_invalid(const char *arg)
{
	fprintf(stderr, "Unknown argument: %s\n", arg);
	fprintf(stderr, "Try 'glowshroom --help' for more information.\n");
}

config_t parse_args(int argc, char *argv[])
{
        config_t config = { NULL, { 0, 0, 0}};

        if (argc > 1) {
                for (size_t i = 1; i < (size_t)argc; i++) {
                        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
                                print_help();
                                exit(EXIT_SUCCESS);
                        } else if ((strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--color") == 0) && i + 1 < (size_t)argc) {
                                config.color = hex_to_rgb(argv[i+1]);
                                i++;
                        } else {
                                print_invalid(argv[i]);
                                exit(EXIT_FAILURE);
                        }

                }
        }

        return config;
}
