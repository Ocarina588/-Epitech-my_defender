/*
** EPITECH PROJECT, 2020
** init menu
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

static void go_option(void *arg, ...)
{
    button_t *button = get_button("principal_start");

    button->move.x = -600 * 2;
    button->speed.x = 2000;
}

static void go_levels(void *arg, ...)
{
    button_t *button = get_button("principal_start");
    button->move.y = 600 * 2;
    button->speed.y = 2000;
}

void quit(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    sfRenderWindow_close(game->window.render);
}

static void corner(void)
{
    sfColor color = (sfColor){100, 100, 255, 255};
    new_button(start_menu).sprite(b_wood_rect).size(100, 50)
        .relative("principal_start").normal(rot_right)
        .coord(-290, -290).color(color);

    new_button(start_menu).sprite(b_wood_rect).size(100, 50)
        .relative("principal_start").normal(rot_left)
        .coord(-290, 290).color(color);

    new_button(start_menu).sprite(b_wood_rect).size(100, 50)
        .relative("principal_start").normal(rot_left)
        .coord(290, -290).color(color);

    new_button(start_menu).sprite(b_wood_rect).size(100, 50)
        .relative("principal_start").normal(rot_right)
        .coord(290, 290).color(color);
}

void setup_menu_start(game_t *game)
{
    sfColor color = (sfColor){255, 100, 255, 255};
    new_button(start_menu).sprite(b_wood_square).coord(600, 450 + -600 * 2)
        .size(600, 600).name("principal_start");
    new_button(start_menu).sprite(b_options).size(266, 66)
        .relative("principal_start").coord(0, -49)
        .multiple(normal_effect, hover_effect, click_effect, go_option);
    new_button(start_menu).sprite(b_levels).coord(0, -150).size(266, 66)
        .relative("principal_start").multiple(normal_effect, hover_effect,
        click_effect, go_levels);
    new_button(start_menu).sprite(b_quit).coord(0, 150).size(200, 66)
        .relative("principal_start").multiple(normal_effect, hover_effect,
        click_effect, quit);
    new_button(start_menu).sprite(b_score).size(200, 70).coord(0, 49)
        .relative("principal_start").multiple(normal_effect, hover_effect,
        click_effect, go_to_score);
    new_button(start_menu).sprite(b_menu).coord(0, -300).size(300, 100)
        .color(color).relative("principal_start");
    corner();
}