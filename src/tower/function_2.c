/*
** EPITECH PROJECT, 2020
** function 2
** File description:
** sdf
*/

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "defense.h"

void sell_tower(game_t *game)
{
    sfVector2i coord = sfMouse_getPositionRenderWindow(game->window.render);
    tower_t *tower = NULL;

    if (game->window.pause)
        return;
    if (coord.x < 0 || coord.x > 1200 || coord.y < 0 || coord.y > 900)
        return;
    if (check_good_pos(game, coord) && game->window.time.double_clicked) {
        if (!(tower = check_if_exit(game, coord)))
            return;
        erase_tower(game, tower);
        game->money += 10;
        game->window.time.double_clicked = 0;
    }
}

void upgrade_tower(game_t *game)
{
    sfVector2i coord = sfMouse_getPositionRenderWindow(game->window.render);
    tower_t *tower = NULL;

    if (game->window.pause)
        return;
    if (check_good_pos(game, coord)) {
        if (!(tower = check_if_exit(game, coord)))
            return;
        if (tower->stat.level >= 2 || game->money < 100)
            return;
        tower->stat.level += 1;
        tower->stat.damage *= 1.5;
        tower->stat.radius *= 1.5;
        tower->stat.time *= 50.0F / 100.0F;
        game->money -= 100;
    }
}

void write_score(game_t *game)
{
    int fd = open("sprites/score", O_RDWR);
    char buff[1];
    if (fd == -1) {
        return;
    }
    while (read(fd, buff, 1));
    write(fd, nbstr(game->score), nb_len(game->score));
    write(fd, "\n", 1);
    close(fd);
}

void quite_game_bis(game_t *game)
{
    game->scene[1].plug.tower = NULL;
    game->scene[1].plug.rocket = NULL;
    game->scene[1].monster = NULL;
    write_score(game);
    game->score = 0;
    game->money = 80;
    game->lose = 0;
    init_waves(game);
}

void quite_game(game_t *game)
{
    void *tmp = game->scene[1].plug.tower;
    tower_t *a = game->scene[1].plug.tower;
    rocket_t *b = game->scene[1].plug.rocket;
    monster_t *c = game->scene[1].monster;
    while (a) {
        tmp = a->next;
        free(a);
        a = ((tower_t *)tmp);
    }
    while (b) {
        tmp = b->next;
        free(b);
        b = ((rocket_t *)tmp);
    }
    while (c) {
        tmp = c->next;
        free(c);
        c = ((monster_t *)tmp);
    }
    quite_game_bis(game);
}