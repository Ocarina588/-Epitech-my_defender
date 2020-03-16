/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_levels.c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "defense.h"
#include <unistd.h>

int init_levels(game_t *game)
{
    game->map = malloc(sizeof(map_t) * nb_files("maps"));
    if (!game->map) {
        send_error();
        return (0);
    }
    for (int i = 0; i < nb_files("maps") ; i++) {
        game->map[i] = init_scene_lvl(game->hud.files_c[i]);
        if (game->map[i].good_files == 0)
            game->map[i].coord_tab = init_tab_coord(game, i);
    }
}