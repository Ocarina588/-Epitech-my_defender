/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_monster_bis.c
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

void set_up_rec(sfIntRect *rec, int i, int height, int top)
{
    rec->width = 24;
    rec->height = height;
    rec->left = 15 + 24 * i;
    rec->top = top;
}

void set_up_rec_bis(sfIntRect *rec, int i, int height, int top)
{
    rec->width = 24;
    rec->height = 24;
    rec->left = 268 + 24 * i;
    rec->top = 185;
}