/*
** EPITECH PROJECT, 2020
** init button
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

init_button_func_t get_func_button(void)
{
    init_button_func_t func;

    func.coord = coord;
    func.sprite = sprite;
    func.name = name;
    func.rotation = rotation;
    func.relative = relative;
    func.hover = hover;
    func.normal = normal;
    func.interval = interval;
    func.on_click = on_click;
    func.function = function;
    func.color = color;
    func.size = size;
    func.multiple = multiple;

    return (func);
}

button_t update_init_button(int mode, button_t button, scene_selector i)
{
    static int nb[NB_BUTTON_MAX];
    static scene_selector scene_i = 0;
    static int rep = 0;

    if (!rep) {
        for (int i = 0; i < NB_BUTTON_MAX ; i++)
            nb[i] = -1;
        rep = 1;
    }

    scene_i = mode == 2 ? i : scene_i;
    nb[scene_i] += mode == 2 ? 1 : 0;
    if (mode == 1)
        gg()->scene[scene_i].button[nb[scene_i]] = button;
    if (!mode)
        return (gg()->scene[scene_i].button[nb[scene_i]]);
}

init_button_func_t new_button(scene_selector scene)
{
    button_t button = {.entity = new_entity(), .clicked = 0, .offset = 0};

    update_init_button(2, (button_t){0}, scene);
    button.activated = 1;
    button.move = (sfVector2f){0, 0};
    button.speed = (sfVector2f){0, 0};
    button.interval = (sfVector2f){0, 0};
    button.function = NULL;
    button.hover = NULL;
    button.normal = NULL;
    button.click = NULL;
    button.function = NULL;
    button.entity.transform.size.x = 50;
    button.entity.transform.size.y = 50;
    for (int i = 0; i < 64 ; i++)
        button.relative[i] = 0;
    update_init_button(1, button, scene);
    return (get_func_button());
}