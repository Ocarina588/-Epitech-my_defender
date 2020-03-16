/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_man.c
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

void new_ele_bis(monster_t *new)
{
    new->index = 0;
    new->entity = new_entity();
    new->modulo = 15;
    new->mo = 0;
    new->malus = (malus_t){0, 0, 0};
    new->entity.transform.coord = (sfVector2f){0, 0};
    new->entity.motion.acceleration = (sfVector2f){1, 1};
    new->speed = 1;
}

void new_fox_bis(monster_t *new)
{
    new->index = 0;
    new->entity = new_entity();
    new->modulo = 6;
    new->mo = 1;
    new->entity.transform.coord = (sfVector2f){0, 0};
    new->entity.motion.acceleration = (sfVector2f){2, 2};
    new->speed = 2;
}

void new_man_bis(monster_t *new)
{
    new->index = 0;
    new->entity = new_entity();
    new->modulo = 7;
    new->malus = (malus_t){0, 0, 0};
    new->mo = 2;
    new->entity.transform.coord = (sfVector2f){0, 0};
    new->entity.motion.acceleration = (sfVector2f){1.5, 1.5};
    new->speed = 1.5;
}

monster_t *new_man(void)
{
    monster_t *new = malloc(sizeof(monster_t));
    if (!new) {
        send_error();
        return (NULL);
    }
    new_man_bis(new);
    new->entity.transform.coord =
        (sfVector2f){0 , begin_road(gg(),
        gg()->hud.file_selector) + LEN / 2};
    new->entity.transform.size = (sfVector2f){40, 40};
    new->life = 250;
    new->max_life = 250;
    new->tower = NULL;
    new->coord = 1;
    new->next = NULL;
    return (new);
}

sfSprite **init_man(graphic_t *graphic)
{
    sfIntRect rec = {0, 0, 0, 0};
    sfVector2u size;
    graphic->animals[2] = malloc(sizeof(sfSprite *) * 7);
    for (int i = 0; i < 7; i++) {
        set_up_rec_bis(&rec, i, 0, 0);
        graphic->man[i] =
        sfTexture_createFromFile("sprites/map/atlas.png", &rec);
        if (!graphic->man[i]) {
            send_error();
            return (NULL);
        }
        graphic->animals[2][i] = sfSprite_create();
        sfSprite_setTexture(graphic->animals[2][i], graphic->man[i], sfTrue);
        size = sfTexture_getSize(graphic->man[i]);
        sfSprite_setOrigin(graphic->animals[2][i],
        (sfVector2f){size.x / 2, size.y / 2});
    }
    return (graphic->animals[2]);
}