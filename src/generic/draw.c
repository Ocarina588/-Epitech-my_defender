/*
** EPITECH PROJECT, 2020
** draw generic
** File description:
** sdf
*/

#include "my.h"
#include "defense.h"

void draw_button(button_t button)
{
    if (button.sprite)
        sfRenderWindow_drawSprite(gg()->window.render, button.sprite, NULL);
}

void draw_life(game_t *game, monster_t *monster)
{
    sfVector2f coord = monster->entity.transform.coord;
    int nb = monster->life * 100 / monster->max_life;
    int nb2 = nb * HP_W / 100;
    int size = monster->entity.transform.size.x;
    sfColor magenta = (sfColor){140, 20, 252, 255};
    coord.x = coord.x - HP_W / 2;
    coord.y = coord.y - (size > 0 ? size : -size);
    sfRectangleShape_setFillColor(game->scene[1].plug.life[1],
        monster->malus.poison ? magenta : sfYellow);
    sfRectangleShape_setSize(game->scene[1].plug.life[1],
        (sfVector2f){nb2, HP_H});
    for (int i = 0; i < 2 ; i++) {
        sfRectangleShape_setPosition(game->scene[1].plug.life[i], coord);
    sfRenderWindow_drawRectangleShape(game->window.render,
        game->scene[1].plug.life[i], NULL);
    }
}

void draw_monster(monster_t *monster)
{
    game_t *game = gg();

    if (!monster)
        return;
    draw_life(game, monster);
    sfRenderWindow_drawSprite(game->window.render,
    game->graphic.animals[monster->mo]
        [(int) monster->index % monster->modulo], NULL);
}

void draw_tower(tower_t *tower)
{
    sfCircleShape *circle = gg()->scene[1].plug.circle;
    sfVector2f coord = tower->entity.transform.coord;
    sfColor color[3] = {sfWhite, sfYellow, sfMagenta};

    if (tower->stat.type == tower_slow) {
        sfCircleShape_setRadius(circle, tower->stat.radius);
        sfCircleShape_setOrigin(circle, (sfVector2f){tower->stat.radius,
            tower->stat.radius});
        sfCircleShape_setPosition(circle, coord);
        sfRenderWindow_drawCircleShape(gg()->window.render, circle, NULL);
    }

    sfSprite_setColor(tower->sprite, color[tower->stat.level]);
    sfRenderWindow_drawSprite(gg()->window.render, tower->sprite, NULL);
}

void draw_rocket(rocket_t *rocket)
{
    sfRenderWindow_drawSprite(gg()->window.render, rocket->sprite, NULL);
}