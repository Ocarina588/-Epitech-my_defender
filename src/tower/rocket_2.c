/*
** EPITECH PROJECT, 2020
** rocket 2
** File description:
** sdf
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "defense.h"

float compute_angle_rocket(rocket_t *rocket)
{
    sfVector2f rep = {1, 0};
    float converse = 180 / M_PI;
    float first = scalar_product(get_direction_rocket(rocket), rep);
    float second = vector_norm(get_direction_rocket(rocket));
    float compute = first / second;
    float angle = acos(compute) * converse;
    return (get_direction_rocket(rocket).y >= 0 ? -angle : angle);
}

int check_target(rocket_t *rocket)
{
    sfVector2f a = rocket->entity.transform.coord;
    sfVector2f b = rocket->monster->entity.transform.coord;
    float c = get_distance(a, b);
    c *= c > 0 ? 1 : -1;
    if (c < 30) {
        rocket->monster->life -= rocket->damage;
        rocket->monster->malus.poison += rocket->poison;
        erase_rocket(gg(), rocket);
        return (1);
    }
    return (0);
}

void rocket_manager(game_t *game)
{
    rocket_t *tmp = game->scene[1].plug.rocket;

    while (tmp) {
        if (tmp->monster && check_target(tmp)) {
            rocket_manager(game);
            return;
        }
        tmp = tmp->next;
    }
}

void set_rocket_speed(rocket_t *rocket)
{
    sfVector2f vector = get_direction_rocket(rocket);
    rocket->entity.motion.velocity.x = -vector.x *
        (rocket->speed / vector_norm(vector));
    rocket->entity.motion.velocity.y = -vector.y *
        (rocket->speed / vector_norm(vector));
}