/*
** EPITECH PROJECT, 2020
** mydefencer
** File description:
** jaime les chips
*/

#include "my.h"
#include "defense.h"
#include <stdlib.h>
#include <math.h>

game_t *get_game(int mode, game_t *game)
{
    static game_t *ga = NULL;
    if (mode)
        ga = game;
    return (ga);
}

game_t *gg(void)
{
    return (get_game(0, NULL));
}

void update_dt(game_t *game)
{
    long int old = game->window.time.old_time;
    game->window.time.old_time = sfClock_getElapsedTime(
        game->window.time.clock).microseconds;
    game->window.time.dt = (game->window.time.old_time - old) / 1000000.0F;
}

void my_defender(game_t *game)
{
    sfRenderWindow_clear(game->window.render, sfBlack);
    update_dt(game);
    button_manager(game, 1);

    while (sfRenderWindow_pollEvent(game->window.render, &game->window.event))
        event_manager(game);
    draw_scene(game);
    explosion_effect(game);
    sfRenderWindow_display(game->window.render);
}

int main(int ac, char **av)
{
    game_t game = init_game();
    long long int size = (long long int)malloc(1);
    unsigned int size2 = size;
    get_game(1, &game);
    if (ac > 2 && my_strcmp(av[1], "-h"))
        print("see the howtoplay file in howtoplay folder\n");
    if (check_error()) {
        print("exiting \"./my_defender\" because an error was detected\n");
        return (84);
    }
    srand(size2);
    get_button("principal_start")->move.y = 600 * 2;
    get_button("principal_start")->speed.y = 2000;

    while (sfRenderWindow_isOpen(game.window.render))
        my_defender(&game);
    close_music(game);
    return (0);
}