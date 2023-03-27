/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** frame_loop
*/

#include "rpg.h"
#include <stdlib.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>

void frame_loop(char *filepath)
{
    (void) filepath;
    sfRenderWindow *window = init_window();
    objects_t *objects = create_objects(window);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, objects->background, NULL);
        events_management(window);
        sfRenderWindow_display(window);
    }
    free(objects);
    sfRenderWindow_destroy(window);
    return;
}
