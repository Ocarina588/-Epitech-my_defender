/*
** EPITECH PROJECT, 2020
** button effect
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

void rot_left(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t *button = game->scene[game->actual_scene].button;
    va_list va;
    int nb;
    va_start(va, arg);
    nb = va_arg(va, int);
    button[nb].entity.transform.rotation -= 300 * game->window.time.dt;

    va_end(va);
}