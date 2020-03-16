/*
** EPITECH PROJECT, 2020
** tower menu
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

static void show_menu_bis(button_t *button, button_t tmp)
{
    int y = tmp.entity.transform.coord.y;
    int x = tmp.move.y;

    if (y > 960 && !x) {
        button->entity.transform.coord.y = 970;
        y = 970;
    } else if (y < 820 && !x) {
        button->entity.transform.coord.y = 810;
        y = 810;
    }
    if (is_in_button(tmp) && y == 970) {
        button->move.y = -160;
        button->speed.y = 2000;
    }
    if (!is_in_button(tmp) && y == 810) {
        button->move.y = 160;
        button->speed.y = 2000;
    }
    gg()->scene[1].plug.right_click = y == 970;

}

static void show_menu(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t tmp;
    button_t *button;
    va_list va;
    int nb;

    if (sfMouse_getPositionRenderWindow(gg()->window.render).y > 900
        || game->window.pause)
        return;
    va_start(va, arg);
    nb = va_arg(va, int);
    tmp = game->scene[game->actual_scene].button[nb];
    button = &game->scene[game->actual_scene].button[nb];

    show_menu_bis(button, tmp);

    va_end(va);
}

static void on_select(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t *button;
    va_list va;
    int nb;
    va_start(va, arg);
    nb = va_arg(va, int);

    button = &game->scene[game->actual_scene].button[nb];

    button->entity.transform.size = (sfVector2f){100, 100};
    va_end(va);
}

static void no_select(void *arg, ...)
{
    game_t *game = (game_t *)arg;
    button_t *button;
    va_list va;
    int nb;
    va_start(va, arg);
    nb = va_arg(va, int);

    button = &game->scene[game->actual_scene].button[nb];

    button->entity.transform.size = (sfVector2f){70, 70};
    va_end(va);
}

void setup_chose_tower(game_t *game)
{
    new_button(level).sprite(b_wood_rect).size(100, 50).coord(0, -70)
        .relative("menu_tower");
    new_button(level).sprite(b_wood_rect).coord(600, 970)
        .size(600, 190).color((sfColor){0, 0, 0, 0})
        .name("menu_tower").normal(show_menu);
    new_button(level).sprite(b_wood_bar).relative("menu_tower")
        .size(600, 100).coord(0, 20).name("A");
    new_button(level).sprite(t_slow).relative("A").size(70, 70).coord(-150, 0)
        .multiple(no_select, on_select, NULL, choose_trap);
    new_button(level).sprite(t_sniper).relative("A").size(70, 70).coord(-50, 0)
        .multiple(no_select, on_select, NULL, choose_sniper);
    new_button(level).sprite(t_basic).relative("A").size(70, 70).coord(50, 0)
        .multiple(no_select, on_select, NULL, choose_basic);
    new_button(level).sprite(t_poison).relative("A").size(70, 70).coord(150, 0)
        .multiple(no_select, on_select, NULL, choose_poison);
    money_score(game);
}