/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** monster_manager.c
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "defense.h"

int begin_road(game_t *game, int k)
{
    for (int i = 0; i < 11; i++) {
        if (game->map[k].map_number[i + 1][0] == 'x')
            return (i * LEN);
    }
    return (0);
}

int end_road(game_t *game, int k)
{
    for (int i = 0; i < 11; i++) {
        if (game->map[k].map_number[i][13] == 'x') {
            return (i * LEN);
        }
    }
    return (0);
}

int set_text_wave(int mode, game_t *game)
{
    static float i = 255;
    sfColor color;

    if (mode)
        i = 255;
    if (!mode) {
        game->hud.wave.str[5] = '\0';
        my_strcat(game->hud.wave.str, nbstr(game->wave.nb_waves));
        color = sfText_getColor(game->hud.wave.text);
        i = i - game->window.time.dt * 200;
        if (i <= 0)
            i = 0;
        color.a = i;
        sfText_setColor(game->hud.wave.text, color);
        sfText_setOutlineColor(game->hud.wave.text, color);
        draw(game->hud.wave);
    }
}