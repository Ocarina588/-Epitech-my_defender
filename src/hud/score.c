/*
** EPITECH PROJECT, 2020
** init score
** File description:
** sdf
*/

#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "defense.h"

void init_text_score(game_t *game)
{
    for (int i = 0; i < 3 ; i++) {
        game->hud.score[i][0] = new_text(".....", game);
        game->hud.score[i][1] = new_text(nbstr(i + 1), game);
        game->hud.score[i][0].entity.transform.coord =
            (sfVector2f){50, -120 + i * 100};
        game->hud.score[i][1].entity.transform.coord =
            (sfVector2f){-100, -120 + i * 100};
        my_strcpy(game->hud.score[i][0].relative, "score_start");
        my_strcpy(game->hud.score[i][1].relative, "score_start");
        sfText_setColor(game->hud.score[i][1].text, sfYellow);
    }
}