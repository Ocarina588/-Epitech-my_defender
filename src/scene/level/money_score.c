/*
** EPITECH PROJECT, 2020
** monery score
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

void money_score(game_t *game)
{
    new_button(level).sprite(14).size(30, 30).coord(-400, 0)
        .relative("menu_tower");
    new_button(level).sprite(b_score).size(100, 30). coord(400, 0)
        .relative("menu_tower");
}