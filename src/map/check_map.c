/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** check_map.c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "defense.h"
#include <unistd.h>

int check_pos_x(map_t map, int i, int j)
{
    if (map.map_number[i - 1][j] != 'x' && map.map_number[i + 1][j] != 'x'
    && map.map_number[i][j + 1] != 'x' && map.map_number[i][j - 1] != 'x')
        return (1);
    if (map.map_number[i][j - 1] == 'x' && map.map_number[i][j + 1] != 'x'
    && map.map_number[i  - 1][j] != 'x' && map.map_number[i + 1][j] != 'x')
        return (1);
    if (map.map_number[i - 1][j] == 'x' && map.map_number[i + 1][j] != 'x'
    && map.map_number[i][j - 1] != 'x' && map.map_number[i][j + 1] != 'x')
        return (1);
    return (0);
}

int check_road_y(map_t map, int i)
{
    for (int j = 1; j < 13; j++)
        if (map.map_number[i][j] == 'x' && check_pos_x(map, i, j))
            return (1);
    return (0);
}

int check_road(map_t map)
{
    for (int i = 1; i < 10; i++)
        if (check_road_y(map, i))
            return (1);
    return (0);
}