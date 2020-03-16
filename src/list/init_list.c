/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_list.c
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

void push_node(monster_t *monster, game_t *game)
{
    monster_t **head = &game->scene[1].monster;
    monster_t *tmp = (*head);
    if ((*head) == NULL) {
        (*head) = monster;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = monster;
}

void remove_m(monster_t *a, game_t *game)
{
    monster_t **head = &game->scene[1].monster;
    monster_t *tmp = (*head);
    monster_t *old = NULL;
    if ((*head) == NULL)
        return;
    if (tmp == a) {
        (*head) = tmp->next;
        if (tmp->tower)
            tmp->tower->monster = NULL;
        free(tmp);
        return;
    }
    while (tmp && tmp != a) {
        old = tmp;
        tmp = tmp->next;
    }
    old->next = tmp->next;
    if (tmp->tower)
        tmp->tower->monster = NULL;
    free(tmp);
}

void restart_level(game_t *game)
{
    init_waves(game);
    monster_t **head = &game->scene[1].monster;
    monster_t *tmp = (*head);
    monster_t *old = tmp->next;

    if ((*head) == NULL)
        return;
    while (old) {
        old = tmp->next;
        free(tmp);
    }
}