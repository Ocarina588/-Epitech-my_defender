/*
** EPITECH PROJECT, 2020
** coord generic
** File description:
** sdf
*/

#include "my.h"
#include "defense.h"
#include <math.h>

void button_coord(button_t *button, float x, float y)
{
    button->entity.transform.coord.x = x;
    button->entity.transform.coord.y = y;
}

void move_monster(monster_t *monster)
{
    game_t *game = gg();
    if (monster->malus.frozen)
        defreez(monster, game);
    monster->entity.transform.coord.x +=
        monster->entity.motion.velocity.x *
        game->window.time.dt * monster->entity.motion.acceleration.x;
    monster->entity.transform.coord.y +=
        monster->entity.motion.velocity.y *
        game->window.time.dt * monster->entity.motion.acceleration.y;
}

void update_monster(monster_t *monster)
{
    game_t *game = gg();
    sfSprite *spr;
    monster->index += game->window.time.dt * 10;
    spr = game->graphic.animals
        [monster->mo][(int)monster->index % monster->modulo];
    monster->malus.time += game->window.time.dt;
    if (monster->malus.poison && monster->malus.time > 0.4) {
        monster->life -= 2;
        monster->malus.time = 0;
    }
    if (monster->malus.frozen) {
        monster->entity.motion.acceleration =
        (sfVector2f){monster->speed / 2, monster->speed / 2};
    } else {
        monster->entity.motion.acceleration =
        (sfVector2f){monster->speed, monster->speed};
    }
    move_monster(monster);
    update_entity(spr, monster->entity);
}

void update_tower(tower_t *tower)
{
    tower->stat.time_spend += gg()->window.time.dt;
    update_rotation_tower(tower);
    update_entity(tower->sprite, tower->entity);
}

void update_rocket(rocket_t *rocket)
{
    rocket->entity.transform.coord.x += rocket->entity.motion.velocity.x
        * gg()->window.time.dt;
    rocket->entity.transform.coord.y += rocket->entity.motion.velocity.y
        * gg()->window.time.dt;

    if (rocket->monster) {
        set_rocket_speed(rocket);
        rocket->entity.transform.rotation =
            (compute_angle_rocket(rocket) + 90) * -1;
    }
    update_entity(rocket->sprite, rocket->entity);
}