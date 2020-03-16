/*
** EPITECH PROJECT, 2020
** button effect
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

void hover_effect(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t *button = game->scene[game->actual_scene].button;
    va_list va;
    int nb;
    static int i = 0;

    va_start(va, arg);
    nb = va_arg(va, int);

    if (button[nb].activated)
        sfSprite_setColor(button[nb].sprite, sfYellow);

    va_end(va);
}

void hover_gray(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t *button = game->scene[game->actual_scene].button;
    va_list va;
    sfColor color = {200, 200, 200, 255};
    int nb;

    va_start(va, arg);
    nb = va_arg(va, int);

    sfSprite_setColor(button[nb].sprite, color);

    va_end(va);
}

void click_effect(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t *button = game->scene[game->actual_scene].button;
    va_list va;
    int nb;

    va_start(va, arg);
    nb = va_arg(va, int);

    if (button[nb].activated)
        sfSprite_setColor(button[nb].sprite, sfRed);

    va_end(va);
}

void normal_effect(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t *button = game->scene[game->actual_scene].button;
    va_list va;
    int nb;
    sfColor color = {150, 150, 150, 255};

    va_start(va, arg);
    nb = va_arg(va, int);

    if (button[nb].activated)
        sfSprite_setColor(button[nb].sprite, sfWhite);
    else
        sfSprite_setColor(button[nb].sprite, color);

    va_end(va);
}

void rot_right(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t *button = game->scene[game->actual_scene].button;
    va_list va;
    int nb;
    va_start(va, arg);
    nb = va_arg(va, int);
    button[nb].entity.transform.rotation += 300 * game->window.time.dt;

    va_end(va);
}