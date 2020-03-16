/*
** EPITECH PROJECT, 2020
** init window
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

window_t init_window(void)
{
    window_t window;

    window.mode.bitsPerPixel = 32;
    window.mode.height = 600 * 1.5;
    window.mode.width = 800 * 1.5;
    window.render = sfRenderWindow_create(window.mode,
        "my defender", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window.render, 60);
    window.time.clock = sfClock_create();
    window.time.dt = 0;
    window.time.old_time = 0;
    window.time.realesed_time = 0;
    window.len_tile = window.mode.width / 12;
    window.fps = 0;
    window.pause = 0;
    if (!window.render)
        send_error();
    return (window);
}