/*
** EPITECH PROJECT, 2020
** rocket
** File description:
** sdf
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "defense.h"

rocket_t *new_rocket(game_t *game, tower_t *tower, int type)
{
    rocket_t *rocket = malloc(sizeof(rocket_t));
    sfVector2u size = sfTexture_getSize(game->graphic.tower[type]);
    rocket->entity = new_entity();
    rocket->sprite = sfSprite_create();
    sfSprite_setTexture(rocket->sprite, game->graphic.tower[type], sfTrue);
    sfSprite_setOrigin(rocket->sprite, (sfVector2f){size.x /2, size.y / 2});
    rocket->entity.motion.velocity = get_direction_vector(tower);
    rocket->monster = tower->monster;
    rocket->damage = tower->stat.damage;
    rocket->poison = tower->stat.type == tower_poison;
    rocket->entity.transform.size = (sfVector2f){50, 50};
    rocket->entity.transform.rotation = (compute_angle(tower) + 90) * -1;
    rocket->entity.transform.coord = tower->entity.transform.coord;
    rocket->next = NULL;
    rocket->speed = 500;
    return (rocket);
}

void push_rocket(rocket_t *rocket, game_t *game)
{
    rocket_t **head = &game->scene[1].plug.rocket;
    rocket_t *tmp = game->scene[1].plug.rocket;

    if (!*head) {
        *head = rocket;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = rocket;
}

void erase_rocket(game_t *game, rocket_t *a)
{
    rocket_t **head = &game->scene[1].plug.rocket;
    rocket_t *tmp = game->scene[1].plug.rocket;
    rocket_t *hold = NULL;
    if ((*head) == a) {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
        return;
    }
    while (tmp && tmp != a) {
        hold = tmp;
        tmp = tmp->next;
    }
    hold->next = tmp->next;
    free(tmp);
}

sfVector2f get_direction_rocket(rocket_t *rocket)
{
    sfVector2f coord = {1, 1};

    coord = rocket->monster->entity.transform.coord;
    coord.x = rocket->entity.transform.coord.x - coord.x;
    coord.y = rocket->entity.transform.coord.y - coord.y;

    return (coord);
}

void draw_rock(game_t *game)
{
    rocket_t *tmp = game->scene[1].plug.rocket;

    while (tmp) {
        if (!game->window.pause)
            update(tmp);
        draw(tmp);
        tmp = tmp->next;
    }
}