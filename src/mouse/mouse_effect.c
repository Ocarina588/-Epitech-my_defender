/*
** EPITECH PROJECT, 2019
** Graphics
** File description:
** effect_of_monster_explosion.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include "defense.h"

void my_put_pixel(framebuffer_t *framebuffer , int x, int y, sfColor color)
{
    if (x >= 0 && x < framebuffer->x && y >= 0 && y < framebuffer->y) {
        framebuffer->pixels[(y * framebuffer->x + x) * 4] = color.r;
        framebuffer->pixels[(y * framebuffer->x + x) * 4 + 1] = color.g;
        framebuffer->pixels[(y * framebuffer->x + x) * 4 + 2] = color.b;
        framebuffer->pixels[(y * framebuffer->x + x) * 4 + 3] = color.a;
    }
}

void draw_neg_line(framebuffer_t *fr, sfVector2i point_a,
    sfVector2i point_b, sfColor color)
{
    float x = 0;
    float y = 0;
    float b = point_a.y - point_b.y;
    float az = ((float)(point_b.x - point_a.x)) / (point_b.y - point_a.y);

    if (b > 0)
        for (; y <= b; y++, x += az)
            my_put_pixel(fr, point_b.x+x, point_b.y+y, color);
    else if (b < 0)
        for (; y >= b; y--, x -= az)
            my_put_pixel(fr, point_b.x+x, point_b.y+y, color);
}

int draw_line(framebuffer_t *fr, sfVector2i  point_a,
sfVector2i  point_b, sfColor color)
{
    float a = point_a.x - point_b.x;
    float b = point_a.y - point_b.y;
    float x = 0;
    float y = 0;

    if (a == 0 && b == 0)
        return (0);
    else if (a * a > b * b) {
        float az = ((float)(point_b.y - point_a.y)) / (point_b.x - point_a.x);
        if (a > 0)
            for (; x <= a; x++, y += az)
                my_put_pixel(fr, point_a.x-x, point_a.y-y, color);
        else if (a < 0)
            for (; x >= a; x--, y -= az)
                my_put_pixel(fr, point_a.x-x, point_a.y-y, color);
    } else
        draw_neg_line(fr, point_a, point_b, color);
    return (1);
}

framebuffer_t *effect_cursor(framebuffer_t *fr,
    unsigned int width, unsigned int height)
{
    if ((fr = malloc(sizeof(framebuffer_t))) == NULL)
        return (NULL);
    fr->x = width;
    fr->y = height;
    if ((fr->mouse = sfSprite_create()) == NULL)
        return (NULL);
    if ((fr->mouse_tex = sfTexture_create(width, height)) == NULL)
        return (NULL);
    if ((fr->pixels = malloc(sizeof(char) * 4 * width * height)) == NULL)
        return (NULL);
    sfSprite_setTexture(fr->mouse, fr->mouse_tex, sfTrue);
    memset(fr->pixels, 0, sizeof(char) * 4 * fr->x * fr->y);
    return (fr);
}

void explosion_effect(game_t *game)
{
    int length;
    static framebuffer_t *fr = NULL;
    static sfVector2i pos;
    static sfVector2i tmp_pos;
    static int rep = 0;

    if (!fr)
        fr = framebuffer_create(game->window.mode.width,
            game->window.mode.height);
    tmp_pos = !rep ?
        sfMouse_getPositionRenderWindow(game->window.render) : pos;
    length = sizeof(char) * 4 * fr->x * fr->y;
    pos = sfMouse_getPositionRenderWindow(game->window.render);
    draw_line(fr, pos, tmp_pos, sfCyan);
    for (int i = 0; i < length; i++)
        fr->pixels[i] *= 0.9;
    sfTexture_updateFromPixels(fr->mouse_tex, fr->pixels,
        game->window.mode.width, game->window.mode.height, 0, 0);
    sfRenderWindow_drawSprite(game->window.render, fr->mouse, NULL);
    rep = 1;
}