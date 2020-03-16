/*
** EPITECH PROJECT, 2020
** init game
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

const info_tower_t stat[4] = {
    {tower_green, 25, 2, 0, 0, 800},
    {tower_red, 6.25, 0.5, 0, 0, 200},
    {tower_poison, 1, 0.1, 0, 0, 200},
    {tower_slow, 0, 0, 0, 0, 200}
};

static void init_life_rect(game_t *game)
{
    sfRectangleShape **life = game->scene[1].plug.life;
    for (int i = 0; i < 2 ; i++) {
        game->scene[1].plug.life[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(life[i], (sfVector2f){HP_W, HP_H});
    }
    sfRectangleShape_setFillColor(life[0], sfRed);
    sfRectangleShape_setFillColor(life[1], sfGreen);
    sfRectangleShape_setOutlineThickness(life[0], 2);
    sfRectangleShape_setOutlineColor(life[0], sfBlack);

    game->scene[1].plug.rec = sfRectangleShape_create();
    sfRectangleShape_setSize(game->scene[1].plug.rec, (sfVector2f){LEN, LEN});
    sfRectangleShape_setOutlineThickness(game->scene[1].plug.rec, 1);
    sfRectangleShape_setFillColor(game->scene[1].plug.rec,
        (sfColor){0, 0, 0, 0});
    sfRectangleShape_setOutlineColor(game->scene[1].plug.rec, sfBlack);
}

void init_game_bis(game_t *game)
{
    init_scene(game);
    init_hud(game);
    init_start_menu(game);
    init_levels(game);
    init_level_menu(game);
    if (!game->hud.files_c || (!game->hud.files[game->hud.file_selector].text ||
        !game->hud.files[game->hud.file_selector + 1].text))
        get_button("arrow_right")->activated = 0;
    game->scene[1].monster = NULL;
    game->scene[1].plug = (plug_t){NULL, basic, .rocket = NULL,
        .right_click = 0};
    init_life_rect(game);
    game->scene[1].plug.circle = sfCircleShape_create();
    sfCircleShape_setFillColor(game->scene[1].plug.circle,
        (sfColor){25, 181, 254, 100});
}

game_t init_game(void)
{
    game_t game;
    get_game(1, &game);
    game.window = init_window();
    game.graphic = init_graphic();
    game.actual_scene = start_menu;
    game.sound.lvl_music = 50;
    if (check_error())
        return (game);
    init_game_bis(&game);
    init_sound(&game);
    init_waves(&game);
    for (int i = 0; i < 4 ; i++)
        game.scene[1].stat[i] = stat[i];
    game.money = 80;
    game.score = 0;
    game.lose = 0;
    return (game);
}