/*
** EPITECH PROJECT, 2020
** init background
** File description:
** sf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

void init_background(graphic_t *graphic)
{
    char dir[64] = "sprites/background/";
    sfTexture *texture;

    for (int i = 0; i < 8 ; i++, dir[19] = 0) {
        my_strcat(dir, nbstr(i));
        my_strcat(dir, ".png");
        texture = sfTexture_createFromFile(dir, NULL);
        if (!texture) {
            send_error();
            return;
        }
        graphic->background[i] = sfSprite_create();
        if (!graphic->background[i]) {
            send_error();
            return;
        }
        sfSprite_setTexture(graphic->background[i], texture, sfTrue);
        sfSprite_setScale(graphic->background[i], (sfVector2f){3.3, 3.3});
    }
}

void draw_background(game_t *game)
{
    static float i = 0;
    i += 10 * game->window.time.dt;
    if (i < 0)
        i = 0;

    if (game->graphic.background[(int)i % 8])
        sfRenderWindow_drawSprite(game->window.render,
            game->graphic.background[(int)i % 8], NULL);
}