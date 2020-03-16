/*
** EPITECH PROJECT, 2020
** draw manager
** File description:
** sdf
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "defense.h"

int draw_map(int index, int x, int y, float scale)
{
    game_t *game = gg();

    for (int i = 0; i < 8; i++)
        sfSprite_setScale(game->graphic.road[i], (sfVector2f){scale, scale});
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 13; j++) {
            what_sprite_draw((sfVector2i){j, i}, x, y, scale);
            what_turn_draw((sfVector2i){j, i}, x, y, scale);
            what_turn_drawbis((sfVector2i){j, i}, x, y, scale);
            what_turn_drawter((sfVector2i){j, i}, x, y, scale);
            draw_last_turn((sfVector2i){j, i}, x, y, scale);
        }
    }
}

void draw_buttons(game_t *game)
{
    scene_t *scene = &game->scene[game->actual_scene];

    for (int i = 0; i < nb_button_scene[game->actual_scene]; i++) {
        update(&scene->button[i]);
        draw(scene->button[i]);
    }
}

void draw_scene(game_t *game)
{
    game->hud.fps.str[5] = 0;
    my_strcat(game->hud.fps.str, nbstr(1 / game->window.time.dt));

    if (game->actual_scene == start_menu)
        draw_menu(game);
    if (game->actual_scene == level)
        draw_level(game);
    if (game->window.fps)
        draw(game->hud.fps);
    sfMusic_setVolume(game->sound.menu_music, game->sound.lvl_music);
    sfMusic_setVolume(game->sound.battle, game->sound.lvl_music);
    sfSound_setVolume(game->sound.click, game->sound.lvl_music);
    sfSound_setVolume(game->sound.dye, game->sound.lvl_music);
}