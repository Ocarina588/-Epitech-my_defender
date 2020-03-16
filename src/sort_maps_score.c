/*
** EPITECH PROJECT, 2020
** sort
** File description:
** sdf
*/

#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "defense.h"

void swap_map(char **a, char **b)
{
    char *tmp;
    int i = 0;
    while (1) {
        if ((*a)[i] > (*b)[i]) {
            tmp = *a;
            *a = *b;
            *b = tmp;
            break;
        } else if ((*a)[i] < (*b)[i])
            break;
        i++;
    }
}

void sort_maps(char **map)
{
    for (int i = 0; map[i] ; i++)
        for (int j = i + 1 ; map[j] ; j++)
            swap_map(map + i, map + j);
}

int nb_lines(char *name)
{
    int fd  = open(name, O_RDONLY);
    int nb = 0;
    if (fd == -1)
        return (0);
    char *s = get_next_line(fd);

    while (s) {
        nb++;
        free(s);
        s = get_next_line(fd);
    }
    close(fd);
    return (nb);
}

void swap_nb(int *a, int *b)
{
    int tmp;
    if (*a < *b) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

int read_score(game_t *game)
{
    int fd = open("sprites/score", O_RDONLY);
    int nb = nb_lines("sprites/score");
    int *score = malloc(sizeof(int) * nb);

    if (fd == -1 || !score)
        return (0);
    for (int i = 0; i < nb ; i++)
        score[i] = my_getnbr(get_next_line(fd));
    for (int i = 0; i < nb ; i++) {
        if (i == 3)
            break;
        for (int j = i + 1 ; j < nb ; j++)
            swap_nb(score + i, score + j);
        my_strcpy(game->hud.score[i][0].str, nbstr(score[i]));
    }
    return (0);
}