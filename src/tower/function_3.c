/*
** EPITECH PROJECT, 2020
** function 3
** File description:
** sdf
*/

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "my.h"
#include "defense.h"

void defreez(monster_t *monster, game_t *game)
{
    tower_t *tmp = game->scene[1].plug.tower;
    int rep = 0;
    while (tmp) {
        if (tmp->stat.type == tower_slow &&
        get_distance(monster->entity.transform.coord,
        tmp->entity.transform.coord) <= tmp->stat.radius)
            rep++;
        tmp = tmp->next;
    }
    if (!rep)
        monster->malus.frozen = 0;
}