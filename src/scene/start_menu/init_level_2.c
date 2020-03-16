/*
** EPITECH PROJECT, 2020
** init level
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

static void start_game(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    float x = get_button("lvl_sound_opt")->entity.transform.coord.x;
    ((game_t *)arg)->actual_scene = level;
    get_button("lvl_sound_opt")->entity.transform.coord.x = x;
    sfMusic_stop(game->sound.menu_music);
    sfMusic_play(game->sound.battle);
}

void play_button(game_t *game)
{
    new_button(start_menu).sprite(b_play).relative("level_start").size(200, 66)
        .coord(150, 200).multiple(normal_effect, hover_effect, click_effect,
        start_game).name("play");
}