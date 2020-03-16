/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_monster.c
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

void remove_in_tower_rocket(game_t *game, monster_t *monster)
{
    tower_t *tmp = game->scene[1].plug.tower;
    rocket_t *tmp2 = game->scene[1].plug.rocket;
    rocket_t *old = NULL;
    while (tmp) {
        if (tmp->monster == monster)
            tmp->monster = NULL;
        tmp = tmp->next;
    }

    while (tmp2) {
        if (tmp2->monster == monster) {
            old = tmp2;
            tmp2 = tmp2->next;
            erase_rocket(game, old);
            continue;
        }
        tmp2 = tmp2->next;
    }
}

int youlose(game_t *game)
{
    float x = get_button("lvl_sound_opt")->entity.transform.coord.x;
    sfSprite_setColor(get_button("dark")->sprite, (sfColor){0, 0, 0, 0});
    if (game->actual_scene == level)
        get_button("principal_start")->entity.transform.coord.y =
            450 + 600 * 2;
    game->window.pause = 0;
    game->actual_scene = start_menu;
    get_button("lvl_sound_opt")->entity.transform.coord.x = x;
    sfMusic_stop(game->sound.battle);
    sfMusic_play(game->sound.menu_music);
    quite_game(game);
    write_score(game);
}

int money_plus(game_t *game, monster_t *tmp)
{
    for (int i = 0; i < 3 - game->lose; i++) {
        sfSprite_setPosition(game->graphic.heart, (sfVector2f){i * 58, 0});
        sfRenderWindow_drawSprite
        (game->window.render, game->graphic.heart, NULL);
    }
    if (tmp->life <= 0) {
        game->score += 10;
        game->money += 5;
        sfSound_play(game->sound.dye);
    }
}

void draw_monst(game_t *game)
{
    monster_t *tmp = game->scene[1].monster;
    monster_t *old = NULL;
    while (tmp) {
        money_plus(game, tmp);
        if (tmp->entity.transform.coord.x >= 1200 || tmp->life <= 0) {
            tmp->entity.transform.coord.x >= 1200 ? game->lose++ : game->lose;
            remove_in_tower_rocket(game, tmp);
            remove_m(tmp, game);
            tmp = old;
            if (old == NULL)
                continue;
        }
        algo_path_finding(game, tmp);
        if (!game->window.pause)
            update(tmp);
        draw(tmp);
        old = tmp;
        tmp = tmp->next;
    }
}
