/*
** EPITECH PROJECT, 2020
** level manager
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

void draw_level_text(game_t *game)
{
    my_strcpy(game->hud.money.str, nbstr(game->money));
    my_strcpy(game->hud.scor.str, nbstr(game->score));
    draw(game->hud.money);
    draw(game->hud.scor);
}

void draw_level(game_t *game)
{
    gestion_waves(game);
    draw_map(0, 600, 450, 2.08);
    if (!game->scene[1].plug.right_click)
        draw_gride(game);
    tower_manager(game);
    draw_monst(game);
    draw_rock(game);
    draw_tow(game);
    rocket_manager(game);
    set_dark_pause(game);
    draw_buttons(game);
    draw_level_text(game);
    if (game->lose == 3) {
        game->lose = 0;
        youlose(game);
    }
    draw(game->hud.fps_option);
    set_text_wave(0, game);
    my_strcpy(game->hud.music_lvl.str, nbstr((int)game->sound.lvl_music));
    draw(game->hud.music_lvl);
}