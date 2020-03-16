/*
** EPITECH PROJECT, 2019
** MUL_my_screensaver_2019
** File description:
** manage_framebuffer.c
*/

#include "my.h"
#include "defense.h"
#include <stdlib.h>
#include <string.h>

framebuffer_t *framebuffer_clear(framebuffer_t *framebuffer)
{
    memset(framebuffer->pixels, 0, sizeof(char)
    * 4 * framebuffer->x * framebuffer->y);
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));

    framebuffer->x = width;
    framebuffer->y = height;
    framebuffer->pixels = malloc(sizeof(char) * 4 * width * height);
    framebuffer->mouse = sfSprite_create();
    framebuffer->mouse_tex = sfTexture_create(width, height);
    sfSprite_setTexture(framebuffer->mouse, framebuffer->mouse_tex, sfTrue);
    framebuffer_clear(framebuffer);
    return (framebuffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer);
}

