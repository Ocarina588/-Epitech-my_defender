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

static void go_menu(void *arg, ...)
{
    button_t *button = get_button("principal_start");
    button->move.y = -600 * 2;
    button->speed.y = 2000;
}

static void minus_map(void *arg, ...)
{
    game_t *game = (game_t *)arg;

    if (game->hud.file_selector) {
        game->hud.file_selector--;
        get_button("arrow_right")->activated = 1;
        if (!game->hud.file_selector)
            get_button("arrow_left")->activated = 0;
    }
}

static void plus_map(void *arg, ...)
{
    game_t *game = (game_t *)arg;

    if (game->hud.files[game->hud.file_selector + 1].text) {
        game->hud.file_selector++;
        get_button("arrow_left")->activated = 1;
        if (!game->hud.files[game->hud.file_selector + 1].text)
            get_button("arrow_right")->activated = 0;
    }
}

static void corner(void)
{
    new_button(start_menu).sprite(b_wood_rect).size(100, 50)
        .relative("level_start").normal(rot_right)
        .coord(-290, -290).color(sfGreen);

    new_button(start_menu).sprite(b_wood_rect).size(100, 50)
        .relative("level_start").normal(rot_left)
        .coord(-290, 290).color(sfGreen);

    new_button(start_menu).sprite(b_wood_rect).size(100, 50)
        .relative("level_start").normal(rot_left)
        .coord(290, -290).color(sfGreen);

    new_button(start_menu).sprite(b_wood_rect).size(100, 50)
        .relative("level_start").normal(rot_right)
        .coord(290, 290).color(sfGreen);
}

void setup_level_start(game_t *game)
{
    new_button(start_menu).sprite(b_wood_square).relative("principal_start")
        .name("level_start").coord(0, -600 * 2).size(600, 600);

    new_button(start_menu).sprite(b_back).relative("level_start").size(200, 66)
        .coord(-150, 200).multiple(normal_effect, hover_effect, click_effect,
        go_menu);

    new_button(start_menu).sprite(b_levels).coord(0, -300).size(300, 100)
        .color(sfGreen).relative("level_start");

    new_button(start_menu).sprite(5).relative("level_start").size(70, 70)
        .coord(-200, -170).multiple(normal_effect, hover_effect,
        click_effect, minus_map).name("arrow_left");

    new_button(start_menu).sprite(6).relative("level_start").size(70, 70)
        .coord(200, -170).multiple(normal_effect, hover_effect,
        click_effect, plus_map).name("arrow_right");
    get_button("arrow_left")->activated = 0;
    corner();
    play_button(game);
}