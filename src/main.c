#include "render.h"
#include "config.h"
#include "template.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "glowshroom.h"

int main(int argc, char *argv[])
{
        srand(time(NULL));

        config_t config = parse_args(argc, argv);

        glowshroom_t gshroom = glowshroom_create(&config);

        int width, height;
        template_size(gshroom.tpl, &width, &height);

        buffer_t *buf = buffer_create(width, height);

        glowshroom_render(buf, &gshroom);
	buffer_render(buf);
	buffer_destroy(buf);

	return 0;
}
