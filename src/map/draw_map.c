/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_map.c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "defense.h"

void what_sprite_draw(sfVector2i pos, int x, int y, float scale)
{
    game_t *game = gg();
    map_t map = game->map[game->hud.file_selector];
    int j = pos.x;
    int i = pos.y;

    if (map.map_number[i][j] == '.') {
        sfSprite_setPosition(game->graphic.road[3], (sfVector2f)
        {(j - 1) * 48 * scale + x - (x * scale / 2.08) ,
        ((i - 1) * 48 * scale + y - (y * scale / 2.08))});
        sfRenderWindow_drawSprite
        (game->window.render, game->graphic.road[3], NULL);
    }
    if (map.map_number[i][j] == '4') {
        sfSprite_setPosition(game->graphic.road[7], (sfVector2f)
        {((j - 1) * 48 * scale + x - (x * scale / 2.08)),
        ((i - 1) * 48 * scale + y - (y * scale / 2.08))});
        sfRenderWindow_drawSprite
        (game->window.render, game->graphic.road[7], NULL);
    }
}

void what_turn_draw(sfVector2i pos, int x, int y, float scale)
{
    game_t *game = gg();
    map_t map = game->map[game->hud.file_selector];
    int j = pos.x;
    int i = pos.y;
    if (map.map_number[i][j] == 'x' && map.map_number[i][j + 1]
    == 'x' && map.map_number[i][j - 1] == 'x'){
        sfSprite_setPosition(game->graphic.road[1], (sfVector2f)
        {((j - 1) * 48 * scale + x - (x * scale / 2.08)),
            ((i - 1) * 48 * scale + y - (y * scale / 2.08))});
        sfRenderWindow_drawSprite
        (game->window.render, game->graphic.road[1], NULL);
    }
    if (map.map_number[i][j] == 'x' && map.map_number[i + 1][j]
    == 'x' && map.map_number[i][j - 1] == 'x'){
        sfSprite_setPosition(game->graphic.road[2], (sfVector2f)
        {((j - 1) * 48 * scale + x - (x * scale / 2.08)),
            ((i - 1) * 48 * scale + y - (y * scale / 2.08))});
        sfRenderWindow_drawSprite
        (game->window.render, game->graphic.road[2], NULL);
    }
}

void what_turn_drawbis(sfVector2i pos, int x, int y, float scale)
{
    game_t *game = gg();
    map_t map = game->map[game->hud.file_selector];
    int j = pos.x;
    int i = pos.y;
    if (map.map_number[i][j] == 'x' && map.map_number[i - 1][j]
    == 'x' && map.map_number[i][j - 1] == 'x'){
        sfSprite_setPosition(game->graphic.road[6], (sfVector2f)
        {((j - 1) * 48 * scale + x - (x * scale / 2.08)),
            ((i - 1) * 48 * scale + y - (y * scale / 2.08))});
        sfRenderWindow_drawSprite
        (game->window.render, game->graphic.road[6], NULL);
    }
    if (map.map_number[i][j] == 'x' && map.map_number[i - 1][j]
    == 'x' && map.map_number[i][j + 1] == 'x'){
        sfSprite_setPosition(game->graphic.road[4], (sfVector2f)
        {((j - 1) * 48 * scale + x - (x * scale / 2.08)),
            ((i - 1)* 48 * scale + y - (y * scale / 2.08))});
        sfRenderWindow_drawSprite
        (game->window.render, game->graphic.road[4], NULL);
    }
}

void what_turn_drawter(sfVector2i pos, int x, int y, float scale)
{
    game_t *game = gg();
    map_t map = game->map[game->hud.file_selector];
    int j = pos.x;
    int i = pos.y;
    if (map.map_number[i][j] == 'x' && map.map_number[i + 1][j]
    == 'x' && map.map_number[i][j + 1] == 'x'){
        sfSprite_setPosition(game->graphic.road[0], (sfVector2f)
        {((j - 1) * 48 * scale + x - (x * scale  /2.08)),
            ((i - 1) * 48 * scale + y - (y * scale / 2.08))});
        sfRenderWindow_drawSprite
        (game->window.render, game->graphic.road[0], NULL);
    }
    if (map.map_number[i][j] == 'x' && map.map_number[i - 1][j]
    == 'x' && map.map_number[i + 1][j] == 'x'){
        sfSprite_setPosition(game->graphic.road[6], (sfVector2f)
        {((j - 1) * 48 * scale + x - (x * scale  / 2.08)),
            ((i - 1) * 48 * scale + y - (y * scale / 2.08))});
        sfRenderWindow_drawSprite
        (game->window.render, game->graphic.road[6], NULL);
    }
}

void draw_last_turn(sfVector2i pos, int x, int y, float scale)
{
    game_t *game = gg();
    map_t map = game->map[game->hud.file_selector];
    int j = pos.x;
    int i = pos.y;

    if (map.map_number[i][j] == 'x' && map.map_number[i - 1][j]
    == 'x' && map.map_number[i][j - 1] == 'x'){
        sfSprite_setPosition(game->graphic.road[5], (sfVector2f)
        {((j - 1) * 48 * scale + x - (x * scale / 2.08)),
            ((i - 1) * 48 * scale + y - (y * scale / 2.08))});
        sfRenderWindow_drawSprite
        (game->window.render, game->graphic.road[5], NULL);
    }
}