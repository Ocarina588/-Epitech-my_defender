/*
** EPITECH PROJECT, 2020
** size generic
** File description:
** sdf
*/

#include "my.h"
#include "defense.h"

void button_size(button_t *button, float w, float h)
{
    transform_t *transform = &button->entity.transform;
    sfVector2u original = {1, 1};
    if (button->sprite && sfSprite_getTexture(button->sprite))
        original = sfTexture_getSize(sfSprite_getTexture(button->sprite));
    transform->scale = (sfVector2f){w / original.x, h / original.y};
    transform->size = (sfVector2f){w, h};
}