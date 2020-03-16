/*
** EPITECH PROJECT, 2020
** init graphic
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

sfTexture **init_tower(void)
{
    sfTexture **tower = malloc(sizeof(sfSprite *) * NB_TOWER);
    char dir[64] = "sprites/tower/";

    if (!tower) {
        print("fail malloc\n");
        send_error();
        return (NULL);
    }
    for (int i = 0; i < NB_TOWER ; i++, dir[14] = 0) {
        my_strcat(dir, nbstr(i + 1));
        my_strcat(dir, ".png");

        tower[i] = sfTexture_createFromFile(dir, NULL);
        if (!tower[i])
            send_error();
    }
    return (tower);
}

void init_button(graphic_t *graphic)
{
    char dir[64] = "sprites/button/";
    sfTexture **button = graphic->button;

    for (int i = 0; i < NB_BUTTON ; i++, dir[15] = 0) {
        my_strcat(dir, nbstr(i + 1));
        my_strcat(dir, ".png");

        button[i] = sfTexture_createFromFile(dir, NULL);
        if (!button[i])
            send_error();
    }
}

void init_heart(graphic_t *graphic)
{
    sfIntRect rec = {0, 0, 0, 0};

    rec.width = 282;
    rec.height = 282;
    rec.left = 16;
    rec.top = 0;
    graphic->tex_heart =
    sfTexture_createFromFile("sprites/map/heart.png", &rec);
    if (!graphic->tex_heart)
        send_error();
    graphic->heart = sfSprite_create();
    sfSprite_setTexture(graphic->heart, graphic->tex_heart, sfTrue);
    sfSprite_setScale(graphic->heart, (sfVector2f){0.2, 0.2});
}

void init_map(graphic_t *graphic)
{
    sfIntRect rec = {0, 0, 0, 0};

    for (int i = 0; i < 8; i++) {
        rec.width = 48;
        rec.height = 48;
        rec.left = 48 * i;
        rec.top = 0;
        graphic->map[i] = sfTexture_createFromFile("sprites/map/map.png", &rec);
        if (!graphic->map[i])
            send_error();
        graphic->road[i] = sfSprite_create();
        sfSprite_setTexture(graphic->road[i], graphic->map[i], sfTrue);
    }
}

graphic_t init_graphic(void)
{
    graphic_t graphic;

    graphic.tower = init_tower();
    init_button(&graphic);
    init_background(&graphic);
    init_map(&graphic);
    init_elephant(&graphic);
    init_fox(&graphic);
    init_man(&graphic);
    init_heart(&graphic);
    return (graphic);
}