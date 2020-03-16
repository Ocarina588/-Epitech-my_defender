/*
** EPITECH PROJECT, 2020
** init option 2 c
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

static void sound_mouse(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t *button = get_button("lvl_sound_opt");
    float mouse_coord = get_mouse_pos_button(button, game);
    sfColor color = {100, 100, 100, 255};

    sfSprite_setColor(button->sprite, color);
    button->entity.transform.coord.x = mouse_coord;
    if (mouse_coord > 200)
        button->entity.transform.coord.x = 200;
    if (mouse_coord < -200)
        button->entity.transform.coord.x = -200;
}

static void music_max(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t *button = get_button("lvl_sound_opt");
    button->move.x = 200 - button->entity.transform.coord.x;
    button->speed.x = 600;
}

static void music_min(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t *button = get_button("lvl_sound_opt");
    button->move.x = -200 - button->entity.transform.coord.x;
    button->speed.x = 600;
}

void bar_music(game_t *game, scene_selector scene)
{
    size_t music = ((size_t)(&(game->sound.lvl_music)) - (size_t)game);

    new_button(scene).sprite(b_wood_bar).coord(0, -100).size(500, 50)
        .relative("option_start").name("bar_music_option_start");
    new_button(scene).sprite(b_wood_square).coord(0, 0).size(50, 100)
        .relative("bar_music_option_start").name("lvl_sound_opt")
        .multiple(normal_effect, hover_gray, sound_mouse, NULL)
        .interval(-200, 200, music);
    new_button(scene).sprite(12).coord(-200, -100).size(50, 50)
        .relative("bar_music_option_start")
        .multiple(normal_effect, hover_gray, click_effect, music_min);
    new_button(scene).sprite(11).coord(200, -100).size(50, 50)
        .relative("bar_music_option_start")
        .multiple(normal_effect, hover_gray, click_effect, music_max);
}