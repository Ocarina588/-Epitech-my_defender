/*
** EPITECH PROJECT, 2020
** inti option
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

static void go_menu(void *arg, ...)
{
    button_t *button = get_button("principal_start");
    button->move.x = 600 * 2;
    button->speed.x = 2000;
}

static void fps_controller(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    game->window.fps = ++game->window.fps % 2;
}

void normal_fps(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t *button = game->scene[game->actual_scene].button;
    va_list va;
    int nb;
    sfColor color = {150, 150, 150, 255};
    va_start(va, arg);
    nb = va_arg(va, int);
    if (button[nb].activated)
        sfSprite_setColor(button[nb].sprite, sfWhite);
    else
        sfSprite_setColor(button[nb].sprite, color);
    if (game->window.fps) {
        sfSprite_setTexture(button[nb].sprite,
            game->graphic.button[b_on], sfTrue);
    } else {
        sfSprite_setTexture(button[nb].sprite,
            game->graphic.button[b_off], sfTrue);
    }
    va_end(va);
}

void corner_option(scene_selector scene)
{
    new_button(scene).sprite(b_wood_rect).size(100, 50)
        .relative("option_start").normal(rot_right)
        .coord(-290, -290).color(sfCyan);

    new_button(scene).sprite(b_wood_rect).size(100, 50)
        .relative("option_start").normal(rot_left)
        .coord(-290, 290).color(sfCyan);

    new_button(scene).sprite(b_wood_rect).size(100, 50)
        .relative("option_start").normal(rot_left)
        .coord(290, -290).color(sfCyan);

    new_button(scene).sprite(b_wood_rect).size(100, 50)
        .relative("option_start").normal(rot_right)
        .coord(290, 290).color(sfCyan);
}

void setup_option_start(game_t *game, scene_selector scene, char *name)
{
    new_button(scene).sprite(b_wood_square).relative(name)
        .name("option_start").coord(600 * 2, 0).size(600, 600);
    new_button(scene).sprite(b_back).relative("option_start").size(200,
        66).coord(0, 200).multiple(normal_effect, hover_effect, click_effect,
        go_menu);
    new_button(scene).sprite(b_options).coord(0, -300).size(300, 100)
        .color(sfCyan).relative("option_start");
    new_button(scene).sprite(b_off).coord(0, 85).size(150, 50)
        .relative("option_start")
        .multiple(normal_fps, hover_effect, click_effect, fps_controller)
        .name("on\\off");
    bar_music(game, scene);
    corner_option(scene);
}