#include "config.h"
#include "render.h"
#include "template.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void print_species_list(FILE *f)
{
	fprintf(f, "  mycena_chlorophos, panellus, omphalotus_olearius,\n");
	fprintf(f, "  mycena_luxaeterna, armillaria_mellea, mycena_silvaelucens\n");
}

static void print_help(void)
{
	fprintf(stdout, "\nglowshroom - Bioluminescent mushrooms in your terminal\n\n");
	fprintf(stdout, "USAGE:\n");
	fprintf(stdout, "  glowshroom [OPTIONS]\n\n");
	fprintf(stdout, "OPTIONS:\n");
	fprintf(stdout, "  -h, --help     Show this help\n");
	fprintf(stdout, "  -c, --color    Set mushroom color (hex, e.g. #ff00ff)\n");
	fprintf(stdout, "  -s, --species  Set mushroom species\n\n");
	fprintf(stdout, "SPECIES:\n");
	print_species_list(stdout);
	fprintf(stdout, "\n");
}

static void print_invalid(const char *arg)
{
	fprintf(stderr, "Unknown argument: %s\n", arg);
	fprintf(stderr, "Try 'glowshroom --help' for more information.\n");
}

static int is_valid_hex(const char *s)
{
        if (!s || s[0] != '#' || strlen(s) != 7) return 0;
        for (int i = 1; i < 7; i++) {
                if (!isxdigit(s[i])) return 0;
        }
        return 1;
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
                                if (!is_valid_hex(argv[i+1])) {
                                        fprintf(stderr, "Invalid color: %s\n", argv[i+1]);
                                        exit(EXIT_FAILURE);
                                }
                                config.color = hex_to_rgb(argv[i+1]);
                                i++;
                        } else if ((strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--species") == 0) && i + 1 < (size_t)argc) {
                                if (!template_exists(argv[i+1])) {
                                        fprintf(stderr, "Unknown species: %s\n", argv[i+1]);
                                        fprintf(stderr, "Available:\n");
                                        print_species_list(stderr);
                                        exit(EXIT_FAILURE);
                                }
                                config.species = argv[i+1];
                                i++;
                        } else {
                                print_invalid(argv[i]);
                                exit(EXIT_FAILURE);
                        }

                }
        }

        return config;
}
