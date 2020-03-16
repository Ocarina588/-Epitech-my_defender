/*
** EPITECH PROJECT, 2020
** entity manager
** File description:
** sdf
*/

#include "my.h"
#include "defense.h"

void update_entity(sfSprite *sprite, entity_t entity)
{
    sfVector2u original = {1, 1};
    transform_t transform = entity.transform;

    if (!sprite)
        return;
    if (sfSprite_getTexture(sprite))
        original = sfTexture_getSize(sfSprite_getTexture(sprite));

    transform.scale = (sfVector2f){transform.size.x / original.x,
        transform.size.y / original.y};
    sfSprite_setScale(sprite, transform.scale);
    sfSprite_setPosition(sprite, transform.coord);
    sfSprite_setRotation(sprite, transform.rotation);
}

button_t *get_button(char *name)
{
    button_t *tab = gg()->scene[gg()->actual_scene].button;

    for (int i = 0; i < nb_button_scene[gg()->actual_scene] ; i++)
        if (!my_strcmp(name, tab[i].entity.name))
            return (tab + i);
    return (NULL);
}

void move_button(button_t *bu)
{
    float dt = gg()->window.time.dt;
    sfVector2f sp = {dt * bu->speed.x, dt * bu->speed.y};

    if (bu->move.x) {
        if (sp.x < bu->move.x * (bu->move.x > 0 ? 1 : -1)) {
            bu->entity.transform.coord.x += sp.x * (bu->move.x > 0 ? 1 : -1);
            bu->move.x -= sp.x * (bu->move.x > 0 ? 1 : -1);
        } else {
            bu->entity.transform.coord.x += bu->move.x;
            bu->move.x = 0;
        }
    }
    if (bu->move.y) {
        if (sp.y < bu->move.y * (bu->move.y > 0 ? 1 : -1)) {
            bu->entity.transform.coord.y += sp.y * (bu->move.y > 0 ? 1 : -1);
            bu->move.y -= sp.y * (bu->move.y > 0 ? 1 : -1);
        } else {
            bu->entity.transform.coord.y += bu->move.y;
            bu->move.y = 0;
        }
    }
}

void button_interval(button_t *bu)
{
    float sound;
    game_t *game = gg();

    if (bu->interval.x || bu->interval.y) {
        sound = ( bu->entity.transform.coord
        .x + (bu->interval.x > 0 ? (bu->interval.x) : -bu->interval.x) ) * 100
        / (bu->interval.y + (bu->interval.x > 0 ? (bu->interval.x) :
        -bu->interval.x));
        if (sound < 0)
            sound = 0;
        else if (sound > 100)
            sound = 100;
        *((float *)((size_t)game + bu->offset)) = sound;
    }
}

void update_button(button_t *bu)
{
    button_t parent;
    button_t tmp = *bu;
    button_t but = *bu;

    move_button(bu);
    button_interval(bu);

    while (1) {
        if (*tmp.relative) {
            parent = *get_button(tmp.relative);
            but.entity.transform.coord.x += parent.entity.transform.coord.x;
            but.entity.transform.coord.y += parent.entity.transform.coord.y;
            tmp = parent;
        } else
            break;
    }

    update_entity(but.sprite, but.entity);
}