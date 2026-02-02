#include "template.h"
#include <stdlib.h>
#include <string.h>

static const char *mycena_chlorophos[] = {
        "  .@.  ",
        " .@@@. ",
        "  :|:  ",
        "   |   ",
        NULL
};

static const char *panellus[] = {
        "_@@@@@@_",
        " \\@@@@/ ",
        "  '||'  ",
        NULL
};

static const char *omphalotus_olearius[] = {
        "\\______/",
        " \\@@@@/ ",
        "  |--|  ",
        "  |  |  ",
        NULL
};

static const char *mycena_luxaeterna[] = {
        "  o  ",
        " /@\\ ",
        "  :  ",
        "  :  ",
        NULL
};

static const char *armillaria_mellea[] = {
        " (@@@@) ",
        "((@@@@))",
        "  |  |  ",
        "  '--'  ",
        NULL
};

static const char *mycena_silvaelucens[] = {
        " @@@ ",
        "@@@@@",
        "  |  ",
        NULL
};

static const template_t templates[] = {
        {"mycena_chlorophos", mycena_chlorophos, "@.", { 48, 255, 144 }},
        {"panellus", panellus, "@", { 255, 180, 60 }},
        {"omphalotus_olearius", omphalotus_olearius, "@", { 255, 120, 30 }},
        {"mycena_luxaeterna", mycena_luxaeterna, ":", { 180, 255, 180 }},
        {"armillaria_mellea", armillaria_mellea, "@", { 200, 255, 150 }},
        {"mycena_silvaelucens", mycena_silvaelucens, "@", {100, 220, 180 }},
};

#define TEMPLATE_COUNT (sizeof(templates) / sizeof(templates[0]))

const template_t *template_get(const char *name)
{
        if (name) {
                for (size_t i = 0; i < TEMPLATE_COUNT; i++) {
                        if (strcmp(templates[i].name, name) == 0) {
                                return &templates[i];
                        }
                }
        }
        return &templates[0 + rand() % (TEMPLATE_COUNT)];
}
