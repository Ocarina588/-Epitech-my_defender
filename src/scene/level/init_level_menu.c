/*
** EPITECH PROJECT, 2020
** init level menu
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

static void corner(void)
{
    sfColor color = (sfColor){100, 100, 255, 255};
    new_button(level).sprite(b_wood_rect).size(100, 50)
        .relative("principal_start").normal(rot_right)
        .coord(-290, -290).color(color);

    new_button(level).sprite(b_wood_rect).size(100, 50)
        .relative("principal_start").normal(rot_left)
        .coord(-290, 290).color(color);

    new_button(level).sprite(b_wood_rect).size(100, 50)
        .relative("principal_start").normal(rot_left)
        .coord(290, -290).color(color);

    new_button(level).sprite(b_wood_rect).size(100, 50)
        .relative("principal_start").normal(rot_right)
        .coord(290, 290).color(color);
}

static void unset_pause(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    if (game->window.pause) {
        get_button("principal_start")->move.y = 600 * 2;
        get_button("principal_start")->speed.y = 2000;
    }
    game->window.pause = 0;
}

static void go_menu(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    float x = get_button("lvl_sound_opt")->entity.transform.coord.x;
    sfSprite_setColor(get_button("dark")->sprite, (sfColor){0, 0, 0, 0});
    if (game->actual_scene == level)
        get_button("principal_start")->entity.transform.coord.y =
            450 + 600 * 2;
    game->window.pause = 0;
    game->actual_scene = start_menu;
    get_button("lvl_sound_opt")->entity.transform.coord.x = x;
    sfMusic_stop(game->sound.battle);
    sfMusic_play(game->sound.menu_music);
    quite_game(game);
    write_score(game);
}

void setup_level_menu(game_t *game)
{
    sfColor color = (sfColor){255, 100, 255, 255};
    new_button(level).sprite(b_wood_square).coord(600, 450)
        .size(600 * 3, 450 * 3).color((sfColor){0, 0, 0, 0}).name("dark");
    new_button(level).sprite(b_wood_square).coord(600, 450 - 600 * -2)
        .size(600, 600).name("principal_start");
    new_button(level).sprite(b_options).size(266, 66)
        .relative("principal_start").coord(0, -49)
        .multiple(normal_effect, hover_effect, click_effect,
        go_option_menu_level);
    new_button(level).sprite(b_resume).coord(0, -150).size(266, 66)
        .relative("principal_start").multiple(normal_effect, hover_effect,
        click_effect, unset_pause);
    new_button(level).sprite(b_quit).coord(0, 150).size(200, 66)
        .relative("principal_start").multiple(normal_effect, hover_effect,
        click_effect, quit_game_in_level);
    new_button(level).sprite(b_back).size(200, 70).coord(0, 49)
        .relative("principal_start").multiple(normal_effect, hover_effect,
        click_effect, go_menu);
    new_button(level).sprite(b_pause).coord(0, -300).size(300, 100)
        .color(color).relative("principal_start");
}

void init_level_menu(game_t *game)
{
    setup_level_menu(game);
    setup_option_start(game, level, "principal_start");
    setup_chose_tower(game);
    corner();
}