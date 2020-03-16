/*
** EPITECH PROJECT, 2020
** list
** File description:
** sdf
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "defense.h"

tower_t *new_tower(game_t *game, sfVector2f coord,
    float angle)
{
    tower_t *tower = malloc(sizeof(tower_t));
    sfVector2u size;
    if (tower) {
        tower->stat = game->scene[1].stat[game->scene[1].plug.type];
        size = sfTexture_getSize(game->graphic.tower[tower->stat.type]);
        tower->entity = new_entity();
        tower->entity.transform.size = (sfVector2f){70, 70};
        tower->entity.transform.coord = coord;
        tower->sprite = sfSprite_create();
        tower->next = NULL;
        tower->monster = NULL;
        tower->angle_base = angle;
        tower->stat.time_spend = 0;
        tower->entity.transform.rotation = angle;
        sfSprite_setTexture(tower->sprite,
            game->graphic.tower[tower->stat.type], sfTrue);
        sfSprite_setOrigin(tower->sprite,
            (sfVector2f){size.x / 2, size.y / 2});
    }
    return (tower);
}

void push_tower(tower_t *tower, game_t *game)
{
    tower_t **head = &game->scene[1].plug.tower;
    tower_t *tmp = game->scene[1].plug.tower;

    if (!*head) {
        *head = tower;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = tower;
}

void erase_tower(game_t *game, tower_t *a)
{
    tower_t **head = &game->scene[1].plug.tower;
    tower_t *tmp = game->scene[1].plug.tower;
    tower_t *hold = NULL;
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

float chose_angle(sfVector2i coord, game_t *game)
{
    map_t map = game->map[game->hud.file_selector];
    int x = coord.x + 1;
    int y = coord.y + 1;
    if (y && map.map_number[y - 1][x] == 'x')
        return (0);
    if (y != 10 && map.map_number[y + 1][x] == 'x')
        return (-180);
    if (x != 13 && map.map_number[y][x + 1] == 'x')
        return (90);
    if (x && map.map_number[y][x - 1] == 'x')
        return (-90);
    if (y != 10 && x && map.map_number[y + 1][x - 1] == 'x')
        return (-135);
    if (y != 10 && x != 13 && map.map_number[y + 1][x + 1] == 'x')
        return (135);
    if (y && x != 13 && map.map_number[y - 1][x + 1] == 'x')
        return (45);
    if (y && x && map.map_number[y - 1][x - 1] == 'x')
        return (-45);
}

void add_tower(game_t *game)
{
    float size = 100;
    sfVector2i m = sfMouse_getPositionRenderWindow(game->window.render);
    sfVector2i coord = {(int)(m.x / size), (int)(m.y / size)};
    sfVector2i tmp = coord;
    tower_t *tower = NULL;
    coord.x = coord.x * size + size / 2;
    coord.y = coord.y * size + size / 2;

    if (check_if_exit(game, m))
        return;
    if (check_good_pos(game, m) && game->money >= 20) {
        tower = new_tower(game, (sfVector2f){coord.x, coord.y}, 0);
        game->money -= 20;
        tower->entity.transform.rotation = chose_angle(tmp, game);
        tower->angle_base = tower->entity.transform.rotation;
        push_tower(tower, game);
    }
}