/*
** EPITECH PROJECT, 2019
** MUL_mpos.y_defender_2019
** File description:
** end_path.c
*/

#include <stdlib.h>
#include <math.h>
#include "essentile.h"
#include "defense.h"

void change_orientation(monster_t *m, sfVector2f res, game_t *game)
{
    if (res.x < 0)
        if (m->entity.transform.size.x > 0)
            m->entity.transform.size.x *= -1;
    if (res.x > 0)
        if (m->entity.transform.size.x < 0)
            m->entity.transform.size.x *= -1;
}

void end_path(monster_t *m, sfVector2i pos, sfVector2f res, map_t map)
{
    int i = m->coord;

    if (pos.x > map.coord_tab[i].x && res.x > 0) {
        m->entity.transform.coord = map.coord_tab[i];
        m->coord++;
    } else if (pos.x < map.coord_tab[i].x && res.x < 0) {
        m->entity.transform.coord = map.coord_tab[i];
        m->coord++;
    }
    if (pos.y < map.coord_tab[i].y && res.y < 0) {
        m->entity.transform.coord = map.coord_tab[i];
        m->coord++;
    } else if (pos.y > map.coord_tab[i].y && res.y > 0) {
        m->entity.transform.coord = map.coord_tab[i];
        m->coord++;
    }
}