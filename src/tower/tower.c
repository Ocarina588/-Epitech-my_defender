/*
** EPITECH PROJECT, 2020
** tower
** File description:
** sdf
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "defense.h"

void draw_tow(game_t *game)
{
    tower_t *tmp = game->scene[1].plug.tower;

    while (tmp) {
        if (!game->window.pause)
            update(tmp);
        draw(tmp);
        tmp = tmp->next;
    }
    sell_tower(game);
}

monster_t *get_near(tower_t *tower, game_t *game)
{
    monster_t *tmp = game->scene[1].monster;
    monster_t *near = game->scene[1].monster;
    sfVector2f a = tower->entity.transform.coord;
    sfVector2f b;
    float res;
    if (!game->scene[1].monster)
        return (NULL);
    b = near->entity.transform.coord;
    res = get_distance(a, b);
    while (tmp) {
        b = tmp->entity.transform.coord;
        if (get_distance(a, b) < res) {
            res = get_distance(a, b);
            near = tmp;
        }
        tmp = tmp->next;
    }
    if (res > tower->stat.radius)
        near = NULL;
    return (near);
}

void find_and_check_monster(game_t *game, tower_t *tmp)
{
    float speed;

    if (!tmp->monster)
        tmp->monster = get_near(tmp, game);
    if (tmp->monster)
        tmp->monster->tower = tmp;
    if (tmp->monster && get_distance(tmp->entity.transform.coord,
        tmp->monster->entity.transform.coord) > tmp->stat.radius)
        tmp->monster = NULL;
    if (tmp->monster && tmp->stat.time_spend >= tmp->stat.time) {
        if (tmp->stat.type != tower_slow)
            push_rocket(new_rocket(game, tmp, rocket_small), game);
        tmp->stat.time_spend = 0;
    }
    if (tmp->stat.type == tower_slow)
        slow_monster(game, tmp);
}

void update_rotation_tower(tower_t *tower)
{
    float dt = gg()->window.time.dt;
    float res = tower->angle_base - tower->entity.transform.rotation;
    float angle;

    if (tower->monster) {
        angle = (compute_angle(tower) + 90) * -1;
        tower->entity.transform.rotation = angle;
    } else {
        res = tower->angle_base - tower->entity.transform.rotation;
        if ((res > 0 ? res : -res) > 2)
            tower->entity.transform.rotation += dt * 200 * (res > 0 ? 1 : -1);
        else
            tower->entity.transform.rotation = tower->angle_base;
    }
}

void tower_manager(game_t *game)
{
    tower_t *tmp = game->scene[1].plug.tower;
    while (tmp) {
        find_and_check_monster(game, tmp);
        tmp = tmp->next;
    }
}