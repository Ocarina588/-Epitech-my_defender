/*
** EPITECH PROJECT, 2020
** init scene
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

void init_scene(game_t *game)
{
    for (int i = 0; i < NB_SCENE ; i++) {
        for (int j = 0; j < NB_BUTTON_MAX ; j++)
            game->scene[i].button[j] = (button_t){0, 0, 0, 0, 0};
        game->scene[i].monster = NULL;
    }
}