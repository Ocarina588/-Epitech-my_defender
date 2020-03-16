/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_monster.c
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

monster_t *new_monster(int i)
{
    if (i == 1)
        return (new_elephant());
    if (i == 2)
        return (new_fox());
    if (i == 3)
        return (new_man());
    return (NULL);
}

monster_t *new_elephant(void)
{
    monster_t *new = malloc(sizeof(monster_t));
    if (!new) {
        send_error();
        return (NULL);
    }
    new_ele_bis(new);
    new->entity.transform.coord =
        (sfVector2f){0 , begin_road(gg(), gg()->hud.file_selector) + LEN / 2};
    new->entity.transform.size = (sfVector2f){40, 40};
    new->life = 300;
    new->max_life = 300;
    new->tower = NULL;
    new->coord = 1;
    new->next = NULL;
    return (new);
}

monster_t *new_fox(void)
{
    monster_t *new = malloc(sizeof(monster_t));
    if (!new) {
        send_error();
        return (NULL);
    }
    new_fox_bis(new);
    new->entity.transform.coord =
        (sfVector2f){0 , begin_road(gg(), gg()->hud.file_selector) + LEN / 2};
    new->entity.transform.size = (sfVector2f){40, 40};
    new->life = 150;
    new->max_life = 150;
    new->coord = 1;
    new->malus = (malus_t){0, 0, 0};
    new->tower = NULL;
    new->next = NULL;
    return (new);
}

sfSprite **init_elephant(graphic_t *graphic)
{
    sfIntRect rec = {0, 0, 0, 0};
    sfVector2u size;
    graphic->animals[0] = malloc(sizeof(sfSprite *) * 15);
    for (int i = 0; i < 15; i++) {
        set_up_rec(&rec, i, 24, 470);
        graphic->elephant[i] =
        sfTexture_createFromFile("sprites/map/atlas.png", &rec);
        if (!graphic->elephant[i]) {
            send_error();
            return (NULL);
        }
        graphic->animals[0][i] = sfSprite_create();
        sfSprite_setTexture(graphic->animals[0][i], graphic->elephant[i],
            sfTrue);
        size = sfTexture_getSize(graphic->elephant[i]);
        sfSprite_setOrigin(graphic->animals[0][i],
        (sfVector2f){size.x / 2, size.y / 2});
    }
    return (graphic->animals[0]);
}

sfSprite **init_fox(graphic_t *graphic)
{
    sfIntRect rec = {0, 0, 0, 0};
    sfVector2u size;
    graphic->animals[1] = malloc(sizeof(sfSprite *) * 6);
    for (int i = 0; i < 6; i++) {
        set_up_rec(&rec, i, 15, 450);
        graphic->fox[i] =
        sfTexture_createFromFile("sprites/map/atlas.png", &rec);
        if (!graphic->fox[i]) {
            send_error();
            return (NULL);
        }
        graphic->animals[1][i] = sfSprite_create();
        sfSprite_setTexture(graphic->animals[1][i], graphic->fox[i], sfTrue);
        size = sfTexture_getSize(graphic->fox[i]);
        sfSprite_setOrigin(graphic->animals[1][i],
        (sfVector2f){size.x / 2, size.y / 2});
    }
    return (graphic->animals[1]);
}