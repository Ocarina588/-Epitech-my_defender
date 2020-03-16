/*
** EPITECH PROJECT, 2020
** event manager
** File description:
** sdf
*/

#include "my.h"
#include "defense.h"

static void echap_key(game_t *game)
{
    button_t *button;
    float y;

    if (game->actual_scene != level || game->window.event.key.code
        != sfKeyEscape)
        return;
    button = get_button("principal_start");
    y = button->entity.transform.coord.y;
    if (!button->move.y) {
        if (y < 450 + 600 * 2 + 10 && y > 450 + 600 * 2 - 10)
            button->entity.transform.coord.y = 450 + 600 * 2;
    }
    if (!game->window.pause && !button->move.y &&
        button->entity.transform.coord.y == 450 + 600 * 2) {
        button->move.y = 600 * -2;
        button->speed.y = 2000;
        game->window.pause = 1;
    }
}

void update_realesed_time(game_t *game)
{
    long int old = game->window.time.realesed_time;
    game->window.time.realesed_time =
        sfClock_getElapsedTime(game->window.time.clock).microseconds;
    game->window.time.double_clicked =
        (game->window.time.realesed_time - old) < 150000;
}

void set_dark_pause(game_t *game)
{
    button_t *button = get_button("dark");
    float alpha = sfSprite_getColor(button->sprite).a;
    if (game->window.pause)
        if (alpha < 230.0F)
            alpha += 400 * game->window.time.dt;
    if (!game->window.pause)
        if (alpha > 0.0F)
            alpha = alpha - 400 * game->window.time.dt < 0 ? 0 :
            alpha - 400 * game->window.time.dt;
        sfSprite_setColor(button->sprite, (sfColor){0, 0, 0, (char)alpha});
}

void event_manager(game_t *game)
{
    if (game->actual_scene == level &&
        game->window.event.type == sfEvtMouseButtonReleased &&
        game->window.event.mouseButton.button == sfMouseLeft)
        if (!game->window.pause && game->scene[1].plug.right_click)
            add_tower(game);
    if (game->window.event.type == sfEvtClosed)
        sfRenderWindow_close(game->window.render);
    if (game->window.event.type == sfEvtKeyPressed)
        echap_key(game);
    if (game->window.event.type == sfEvtMouseButtonReleased &&
        game->window.event.mouseButton.button == sfMouseLeft)
        button_manager(game, 0);
    if (game->window.event.type == sfEvtMouseButtonReleased &&
        game->window.event.mouseButton.button == sfMouseRight)
        upgrade_tower(game);
    if (game->window.event.type == sfEvtMouseButtonPressed &&
        game->window.event.mouseButton.button == sfMouseLeft)
        button_manager(game, 2);
    if (game->window.event.type == sfEvtMouseButtonReleased);
}