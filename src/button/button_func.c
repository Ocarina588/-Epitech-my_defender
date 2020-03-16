/*
** EPITECH PROJECT, 2020
** butotn func
** File description:
** sdf
*/

#include "my.h"
#include "defense.h"
#include "button.h"

init_button_func_t coord(int x, int y)
{
    button_t button;
    button = update_init_button(0, button, 0);

    set_coord(button, x, y);

    update_init_button(1, button, 0);
    return (get_func_button());
}

init_button_func_t size(int x, int y)
{
    button_t button;
    button = update_init_button(0, button, 0);

    set_size(button, x, y);

    update_init_button(1, button, 0);
    return (get_func_button());
}

init_button_func_t sprite(button_selector i)
{
    button_t button;
    transform_t *transform;
    sfVector2u size = sfTexture_getSize(gg()->graphic.button[i]);

    button = update_init_button(0, button, 0);
    transform = &button.entity.transform;

    button.sprite = sfSprite_create();
    sfSprite_setTexture(button.sprite, gg()->graphic.button[i], sfTrue);
    sfSprite_setOrigin(button.sprite, (sfVector2f){size.x / 2, size.y / 2});
    sfSprite_setPosition(button.sprite, transform->coord);

    update_init_button(1, button, 0);
    return (get_func_button());
}

init_button_func_t hover(void (*func)(void *, ...))
{
    button_t button;
    button = update_init_button(0, button, 0);

    button.hover = func;

    update_init_button(1, button, 0);
    return (get_func_button());
}

init_button_func_t normal(void (*func)(void *, ...))
{
    button_t button;
    button = update_init_button(0, button, 0);

    button.normal = func;

    update_init_button(1, button, 0);
    return (get_func_button());
}

