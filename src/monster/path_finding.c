/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** path_finding.c
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "defense.h"

int what_turn(map_t map, int i, int j, int z)
{
    if (map.map_number[i][j] == 'x' && map.map_number[i + 1][j]
    == 'x' && map.map_number[i][j - 1] == 'x')
        z++;
    if (map.map_number[i][j] == 'x' && map.map_number[i - 1][j]
    == 'x' && map.map_number[i][j - 1] == 'x')
        z++;
    if (map.map_number[i][j] == 'x' && map.map_number[i - 1][j]
    == 'x' && map.map_number[i][j + 1] == 'x')
        z++;
    if (map.map_number[i][j] == 'x' && map.map_number[i + 1][j]
    == 'x' && map.map_number[i][j + 1] == 'x')
        z++;
    return (z);
}

int nb_turn(map_t map)
{
    int z = 0;
    for (int i = 1; i < 10; i++)
        for (int j = 1; j < 13; j++)
            z = what_turn(map, i, j, z);
    return (z);
}

sfVector2i change_vectors(sfVector2i v, int i, int j, int k)
{
    game_t *game = gg();
    map_t map = game->map[k];
    sfVector2i tmp = {v.x, v.y};
    if (tmp.y == 0 && map.map_number[i + 1][j] == 'x') {
        v.y = 1;
        v.x = 0;
    }
    else if (tmp.y == 0 && map.map_number[i - 1][j] == 'x') {
        v.y = -1;
        v.x = 0;
    }
    if (tmp.x == 0 && map.map_number[i][j - 1] == 'x') {
        v.y = 0;
        v.x = -1;
    }
    else if (tmp.x == 0 && map.map_number[i][j + 1] == 'x') {
        v.y = 0;
        v.x = 1;
    }
    return (v);
}

sfVector2f *init_tab_coord(game_t *game, int k)
{
    map_t map = game->map[k];
    sfVector2f *tab = malloc(sizeof(sfVector2f) * (nb_turn(map) + 10));
    int a = 1;
    sfVector2i v = {1, 0};
    if (!tab) {
        send_error();
        return (NULL);
    }
    tab[0] = (sfVector2f){0, begin_road(game, k) + LEN / 2};
    for (int i = begin_road(game, k) / LEN + 1, j = 1;
    (i != end_road(game, k) / LEN || j != 12); i += v.y, j += v.x)
        if (map.map_number[i + v.y][j + v.x] != 'x') {
            v = change_vectors(v, i, j, k);
            tab[a++] = (sfVector2f)
                {(j - 1) * LEN + LEN / 2, (i - 1) * LEN + LEN / 2};
        }
    tab[a++] = (sfVector2f)
    {12 * LEN + LEN / 2, end_road(game, k) - LEN + LEN / 2};
    tab[a] = (sfVector2f){1300, 1300};
    return (tab);
}

int algo_path_finding(game_t *game, monster_t *m)
{
    map_t map = game->map[game->hud.file_selector];
    int i = m->coord;

    if (map.coord_tab[i].x == 1300)
        return (1);
    float d = sqrtf(pow(map.coord_tab[i].x - map.coord_tab[i - 1].x, 2) +
        pow(map.coord_tab[i].y - map.coord_tab[i - 1].y, 2));
    sfVector2f d_2 = {map.coord_tab[i].x - map.coord_tab[i - 1].x,
        map.coord_tab[i].y - map.coord_tab[i - 1].y};
    sfVector2f res = {d_2.x / d, d_2.y / d};
    m->entity.motion.velocity = (sfVector2f){res.x * 40, res.y * 40};
    int x = m->entity.transform.coord.x;
    int y = m->entity.transform.coord.y;
    change_orientation(m, res, game);
    end_path(m, (sfVector2i){x, y}, res, map);
}