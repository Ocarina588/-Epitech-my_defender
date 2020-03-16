/*
** EPITECH PROJECT, 2020
** function
** File description:
** sdf
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "defense.h"

int is_near_map(game_t *game, int y, int x)
{
    int rep = 0;
    map_t map = game->map[game->hud.file_selector];

    if (map.map_number[y][x] == 'x')
        return (0);

    rep += x && map.map_number[y][x - 1] == 'x';
    rep += y && map.map_number[y - 1][x] == 'x';
    rep += y != 11 && map.map_number[y + 1][x] == 'x';
    rep += x != 13 && map.map_number[y][x + 1] == 'x';
    rep += x != 13 && y != 11 && map.map_number[y + 1][x + 1] == 'x';
    rep += x && y && map.map_number[y - 1][x - 1] == 'x';
    rep += x != 13 && y && map.map_number[y - 1][x + 1] == 'x';
    rep += x && y != 11 && map.map_number[y + 1][x - 1] == 'x';

    return (rep);
}

int check_good_pos(game_t *game, sfVector2i m)
{
    float size = 100;
    sfVector2i coord = {(int)(m.x / size), (int)(m.y / size)};
    int x = coord.x + 1;
    int y = coord.y + 1;

    return (is_near_map(game, y, x));
}

void slow_monster(game_t *game, tower_t *tower)
{
    monster_t *tmp = game->scene[1].monster;

    while (tmp) {
        if (get_distance(tower->entity.transform.coord,
            tmp->entity.transform.coord) <= tower->stat.radius) {
            tmp->malus.frozen = 1;
            }
        tmp = tmp->next;
    }
}

tower_t *check_if_exit(game_t *game, sfVector2i coord)
{
    tower_t *tmp = game->scene[1].plug.tower;
    sfVector2f a = {coord.x, coord.y};
    sfVector2f b;

    while (tmp) {
        b = tmp->entity.transform.coord;
        if (get_distance(a, b) < 50)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void draw_gride(game_t *game)
{
    map_t map = game->map[game->hud.file_selector];
    sfVector2f coord = {0, 0};
    sfRectangleShape *rec = game->scene[1].plug.rec;

    for (int i = 1; i <= 9 ; i++)
        for (int j = 1; j <= 12 ; j++) {
            if (!is_near_map(game, i, j))
                continue;
            coord.x = (j - 1) * LEN;
            coord.y = (i - 1) * LEN;
            sfRectangleShape_setPosition(rec, coord);
            sfRenderWindow_drawRectangleShape(game->window.render, rec, NULL);
        }
}