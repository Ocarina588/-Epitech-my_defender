/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_waves.c
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "defense.h"

void init_waves(game_t *game)
{
    game->wave.index = 0;
    game->wave.nb_waves = 1;
    game->wave.nb_monster = 10;
    game->wave.nb = 0;
    game->wave.stop = 1;
    game->wave.time = 0;
    game->wave.check = 0;
}

int nb_monster(game_t *game)
{
    monster_t **head = &game->scene[1].monster;
    monster_t *tmp = (*head);
    int i = 0;

    while (tmp) {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

void choose_coord(game_t *game, monster_t *m)
{
    m->entity.transform.coord = (sfVector2f)
    {0, begin_road(game, game->hud.file_selector) + LEN / 2};
    if (!game->window.pause)
        update(m);
}

void spawn_monster(game_t *game)
{
    int a = 0;
    int nb = 1;

    if (!nb_monster(game) && game->wave.stop == 1)
        set_text_wave(1, game);
    if (game->window.time.old_time / 1000000 % nb == 0
    && game->wave.check == 0) {
        game->wave.time = game->window.time.old_time / 1000000;
        a = rand()%2;
    }
    if (a == 1) {
        monster_t *tmp = new_monster(rand() % 3 + 1);
        push_node(tmp, game);
        choose_coord(game, tmp);
    }
    game->wave.nb += a;
    game->wave.check2 = 1;
    game->wave.stop = 0;
}

int gestion_waves(game_t *game)
{
    if (game->wave.time == game->window.time.old_time / 1000000) {
        game->wave.check = 1;
    } else {
        game->wave.time = 0;
        game->wave.check = 0;
    }
    if (game->wave.nb == 10 * game->wave.nb_waves
    && game->wave.check2 == 1) {
        game->wave.nb_waves++;
        game->wave.stop = 1;
        game->wave.nb = 0;
    }
    if (game->wave.stop == 1 && nb_monster(game)) {
        game->wave.check2 = 0;
        return (1);
    }
    spawn_monster(game);
    return (0);
}