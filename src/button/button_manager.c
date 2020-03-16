/*
** EPITECH PROJECT, 2020
** button manager
** File description:
** sdf
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "defense.h"

const int nb_button_scene[NB_SCENE] = {
    NB_BUTTON_START_MENU,
    NB_BUTTON_LEVEL
};

int is_in_button(button_t button)
{
    sfVector2i coord = sfMouse_getPositionRenderWindow(gg()->window.render);
    transform_t transform = button.entity.transform;
    button_t *parent = NULL;
    while (1) {
        if (!*button.relative)
            break;
        if (!(parent = get_button(button.relative)))
            return (0);
        transform.coord.x += parent->entity.transform.coord.x;
        transform.coord.y += parent->entity.transform.coord.y;
        button = *parent;
    }
    if (coord.x > transform.coord.x - transform.size.x / 2 &&
        coord.x < transform.coord.x + transform.size.x / 2 &&
        coord.y > transform.coord.y - transform.size.y / 2 &&
        coord.y < transform.coord.y + transform.size.y / 2)
        return (1);
    return (0);
}

void button_manager_release(game_t *game)
{
    button_t *button_tab = game->scene[game->actual_scene].button;
    update_realesed_time(game);
    for (int i = 0; i < nb_button_scene[game->actual_scene]; i++) {
        if (!button_tab[i].sprite)
            continue;
        if (!is_in_button(button_tab[i])) {
            button_tab[i].clicked = 0;
            continue;
        }
        if (button_tab[i].clicked)
            button_tab[i].clicked = 0;
        else
            continue;
        if (button_tab[i].function && button_tab[i].activated) {
            sfSound_setPlayingOffset(game->sound.click, (sfTime){200000});
            sfSound_play(game->sound.click);
            button_tab[i].function(game, i);
        }
    }
}

void button_manager_hover(game_t *game)
{
    button_t *button_tab = game->scene[game->actual_scene].button;

    for (int i = 0; i < nb_button_scene[game->actual_scene]; i++) {
        if (!is_in_button(button_tab[i]) || !button_tab[i].sprite)
            continue;
        if (!button_tab[i].hover || !button_tab[i].sprite)
            continue;
        if (button_tab[i].click && button_tab[i].clicked)
            continue;
        button_tab[i].hover(game, i);
    }
}

void button_manger_click(game_t *game)
{
    button_t *button_tab = game->scene[game->actual_scene].button;

    for (int i = 0; i < nb_button_scene[game->actual_scene]; i++) {
        if (!is_in_button(button_tab[i]))
            continue;
        button_tab[i].clicked = 1;
    }
}

void button_manager(game_t *game, int mode)
{
    button_t *button_tab = game->scene[game->actual_scene].button;
    for (int i = 0; i < nb_button_scene[game->actual_scene] ; i++) {
        if (button_tab[i].sprite && button_tab[i].normal)
            button_tab[i].normal(game, i);
        if (button_tab[i].clicked && button_tab[i].click
            && button_tab[i].sprite)
            button_tab[i].click(game, i);
    }

    if (mode == 2)
        button_manger_click(game);
    if (mode == 1)
        button_manager_hover(game);
    if (mode == 0)
        button_manager_release(game);
}