/*
** EPITECH PROJECT, 2020
** button func 3
** File description:
** sdf
*/

#include "my.h"
#include "defense.h"
#include "button.h"

init_button_func_t rotation(float a)
{
    button_t button = update_init_button(0, button, 0);

    set_rotation(button, a);

    update_init_button(1, button, 0);
    return (get_func_button());
}

init_button_func_t color(sfColor color)
{
    button_t button = update_init_button(0, button, 0);

    sfSprite_setColor(button.sprite, color);

    update_init_button(1, button, 0);
    return (get_func_button());
}

init_button_func_t interval(int a, int b, size_t offset)
{
    button_t button = update_init_button(0, button, 0);

    button.offset = offset;
    button.interval.y = b;
    button.interval.x = a;

    update_init_button(1, button, 0);
    return (get_func_button());
}

float get_mouse_pos_button(button_t *button, game_t *game)
{
    float mouse_coord = sfMouse_getPositionRenderWindow(game->window.render).x;
    button_t tmp = *button;
    button_t parent;

    while (1) {
        if (*tmp.relative) {
            parent = *get_button(tmp.relative);
            mouse_coord -= parent.entity.transform.coord.x;
            tmp = parent;
        } else
            break;
    }

    return (mouse_coord);
}