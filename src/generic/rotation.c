/*
** EPITECH PROJECT, 2020
** rotation button
** File description:
** sdf
*/

#include "my.h"
#include "defense.h"
#include "essentile.h"

void button_rotation(button_t *button, float a)
{
    button->entity.transform.rotation = a;
}