/*
** EPITECH PROJECT, 2020
** start menu manager
** File description:
** dsf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

static void draw_text_menu(game_t *game)
{
    if (game->hud.files_c && game->hud.files[game->hud.file_selector].text) {
        if (game->map[game->hud.file_selector].good_files) {
            sfText_setColor(game->hud.files[game->hud.
            file_selector].text, sfRed);
        } else
            sfText_setColor(game->hud.files[game->hud.
            file_selector].text, sfWhite);
        draw(game->hud.files[game->hud.file_selector]);
    } else
        draw(game->hud.error_file);
    my_strcpy(game->hud.music_lvl.str, nbstr((int)game->sound.lvl_music));

    draw(game->hud.music_lvl);
    draw(game->hud.fps_option);
    for (int i = 0; i < 3 ; i++)
        for (int j = 0; j < 2 ; j++)
        draw(game->hud.score[i][j]);
}

void draw_menu(game_t *game)
{
    sfVector2f coord;

    read_score(game);
    draw_background(game);

    draw_buttons(game);
    draw_text_menu(game);
    coord = get_button("principal_start")->entity.transform.coord;
    if (game->hud.files_c) {
        if (!game->map[game->hud.file_selector].good_files) {
            draw_map(0, coord.x, coord.y + 600 * -2, 0.58);
            get_button("play")->activated = 1;
        } else {
            draw(game->hud.file_spec);
            get_button("play")->activated = 0;
        }
    } else {
        draw(game->hud.file_spec);
        get_button("play")->activated = 0;
    }
}