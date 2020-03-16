/*
** EPITECH PROJECT, 2020
** angle
** File description:
** sfd
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "defense.h"

sfVector2f get_direction_vector(tower_t *tower)
{
    sfVector2f direction_vector = {0, 1};
    sfVector2f coord;

    if (tower->monster) {
        coord = tower->monster->entity.transform.coord;
        direction_vector.x = tower->entity.transform.coord.x - coord.x;
        direction_vector.y = tower->entity.transform.coord.y - coord.y;
    }

    return (direction_vector);
}

float scalar_product(sfVector2f u, sfVector2f v)
{
    return (u.x * v.x + u.y * v.y);
}

float vector_norm(sfVector2f u)
{
    return ((float)sqrt(pow((double)u.x, 2) + pow((double)u.y, 2)));
}

float compute_angle(tower_t *tower)
{
    sfVector2f rep = {1, 0};
    float converse = 180 / M_PI;
    float first = scalar_product(get_direction_vector(tower), rep);
    float second = vector_norm(get_direction_vector(tower));
    float compute = first / second;
    float angle = acos(compute) * converse;
    return (get_direction_vector(tower).y >= 0 ? -angle : angle);
}

float get_distance(sfVector2f a, sfVector2f b)
{
    float res = 0;

    res = powf(b.x -a.x, 2);
    res += powf(b.y - a.y, 2);
    res = sqrtf(res);

    return (res);
}