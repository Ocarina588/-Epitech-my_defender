/*
** EPITECH PROJECT, 2020
** init score
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

void go_to_score(void *arg, ...)
{
    get_button("principal_start")->move.x = 600 * 2;
    get_button("principal_start")->speed.x = 2000;
}

static void go_menu(void *arg, ...)
{
    button_t *button = get_button("principal_start");
    button->move.x = -600 * 2;
    button->speed.x = 2000;
}

static void corner(void)
{
    new_button(start_menu).sprite(b_wood_rect).size(100, 50)
        .relative("score_start").normal(rot_right)
        .coord(-290, -290).color(sfCyan);

    new_button(start_menu).sprite(b_wood_rect).size(100, 50)
        .relative("score_start").normal(rot_left)
        .coord(-290, 290).color(sfCyan);

    new_button(start_menu).sprite(b_wood_rect).size(100, 50)
        .relative("score_start").normal(rot_left)
        .coord(290, -290).color(sfCyan);

    new_button(start_menu).sprite(b_wood_rect).size(100, 50)
        .relative("score_start").normal(rot_right)
        .coord(290, 290).color(sfCyan);
}

void setup_score_start(game_t *game)
{
    new_button(start_menu).sprite(b_wood_square).relative("principal_start")
        .name("score_start").coord(-600 * 2, 0).size(600, 600);
    new_button(start_menu).sprite(b_back).relative("score_start").size(200,
        66).coord(0, 200).multiple(normal_effect, hover_effect, click_effect,
        go_menu);
    new_button(start_menu).sprite(b_score).coord(0, -300).size(300, 100)
        .color(sfCyan).relative("score_start");
    corner();
}