/*
** EPITECH PROJECT, 2020
** init start menu
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

void init_start_menu(game_t *game)
{
    setup_menu_start(game);
    setup_option_start(game, start_menu, "principal_start");
    setup_level_start(game);
    setup_score_start(game);
}