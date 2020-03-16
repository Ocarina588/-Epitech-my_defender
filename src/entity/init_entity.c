/*
** EPITECH PROJECT, 2020
** init entyti
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

transform_t init_transform(void)
{
    transform_t transform;

    transform.coord = (sfVector2f){0, 0};
    transform.rotation = 0;
    transform.scale = (sfVector2f){1, 1};
    transform.size = (sfVector2f){0, 0};

    return (transform);
}

motion_t init_motion(void)
{
    motion_t motion;

    motion.acceleration.x = 0;
    motion.acceleration.y = 0;

    motion.velocity.x = 0;
    motion.velocity.y = 0;

    return (motion);
}

entity_t new_entity(void)
{
    entity_t entity;

    entity.transform = init_transform();
    entity.motion = init_motion();
    for (int i = 0; i < 64 ; i++)
        entity.name[i] = 0;

    return (entity);
}