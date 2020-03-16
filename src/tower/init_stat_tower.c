/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_stat_tower.c
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "defense.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void fill_first(char *s, game_t *game, int k, int type)
{
    int i = 0;
    int j = 0;
    char tmp[30];
    game->scene[1].stat[k].type = type;
    for (i = 0; s[i] != ' '; i++)
        tmp[j++] = s[i];
    tmp[j] = '\0';
    game->scene[1].stat[k].damage = (float)getdouble(tmp);
    for (i = i; s[i] == ' ' || s[i] == '\t'; i++);
    for (i = i, tmp[0] = '\0', j = 0; s[i] != ' '; i++)
        tmp[j++] = s[i];
    tmp[j] = '\0';
    game->scene[1].stat[k].time = (float)getdouble(tmp);
    for (i = i; s[i] == ' ' || s[i] == '\t'; i++);
    for (i = i, tmp[0] = '\0', j = 0; s[i] != '\0'; i++)
        tmp[j++] = s[i];
    tmp[j] = '\0';
    game->scene[1].stat[k].radius = (float)getdouble(tmp);
}

void fill_poison(char *s, game_t *game, int k)
{
    int i = 0;
    int j = 0;
    char tmp[30];
    game->scene[1].stat[k].type = tower_poison;
    for (i = 0; s[i] != ' '; i++)
        tmp[j++] = s[i];
    tmp[j] = '\0';
    game->scene[1].stat[k].damage = (float)getdouble(tmp);
    for (i = i; s[i] == ' ' || s[i] == '\t'; i++);
    for (i = i, tmp[0] = '\0', j = 0; s[i] != ' '; i++)
        tmp[j++] = s[i];
    tmp[j] = '\0';
    game->scene[1].stat[k].time = (float)getdouble(tmp);
    for (i = i; s[i] == ' ' || s[i] == '\t'; i++);
    for (i = i, tmp[0] = '\0', j = 0; s[i] != '\0'; i++)
        tmp[j++] = s[i];
    tmp[j] = '\0';
    game->scene[1].stat[k].radius = (float)getdouble(tmp);
}

void fill_gel(char *s, game_t *game, int k)
{
    int i = 0;
    int j = 0;
    char tmp[30];
    game->scene[1].stat[k].type = tower_slow;
    for (i = 0; s[i] != '\0'; i++)
        tmp[j++] = s[i];
    tmp[j] = '\0';
    game->scene[1].stat[k].radius = (float)getdouble(tmp);
}

int check_errors(game_t *game)
{
    int fd = open("stat_tower", O_RDONLY);
    char *s = get_next_line(fd);
    int i = 0;

    game->scene[1].bad_file = 0;
    while (s) {
        i++;
        check_line(s, game);
        s = get_next_line(fd);
    }
    if (i != 4)
        game->scene[1].bad_file = 1;
    if (game->scene[1].bad_file == 1) {
        return (1);
    }
    return (0);
}

void init_stat_tower(game_t *game)
{
    int fd = open("stat_tower", O_RDONLY);
    if (fd == -1) {
        send_error();
        return;
    }
    if (check_errors(game))
        return;
    char *s = get_next_line(fd);
    fill_first(s, game, 0, tower_green);
    s = get_next_line(fd);
    fill_first(s, game, 1, tower_red);
    s = get_next_line(fd);
    fill_poison(s, game, 2);
    s = get_next_line(fd);
    fill_gel(s, game, 3);
    close(fd);
}