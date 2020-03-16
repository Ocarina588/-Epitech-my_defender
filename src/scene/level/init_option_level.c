/*
** EPITECH PROJECT, 2020
** init option level
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

void quit_game_in_level(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    game->actual_scene = start_menu;
    quite_game(game);
    sfRenderWindow_close(game->window.render);
}

void go_option_menu_level(void *arg, ...)
{
    button_t *button = get_button("principal_start");

    button->move.x = 600 * -2;
    button->speed.x = 2000;
}