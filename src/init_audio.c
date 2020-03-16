/*
** EPITECH PROJECT, 2020
** init audio
** File description:
** sd
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"

void init_sound(game_t *game)
{
    char tab[][64] = {{"sprites/menu_music.ogg"}, {"sprites/dye.ogg"}};
    if (
    !(game->sound.menu_music = sfMusic_createFromFile(tab[0])) ||
    !(game->sound.battle = sfMusic_createFromFile("sprites/battle.ogg")) ||
    !(game->sound.buffer[0] =
    sfSoundBuffer_createFromFile("sprites/click.ogg")) ||
    !(game->sound.buffer[1] = sfSoundBuffer_createFromFile(tab[1])) ||
    !(game->sound.click = sfSound_create()) ||
    !(game->sound.dye = sfSound_create())
    ) {
        send_error();
        return;
    }
    sfSound_setBuffer(game->sound.click, game->sound.buffer[0]);
    sfSound_setBuffer(game->sound.dye, game->sound.buffer[1]);
    sfMusic_play(game->sound.menu_music);
    sfMusic_setVolume(game->sound.menu_music, game->sound.lvl_music);
    sfMusic_setLoop(game->sound.menu_music, sfTrue);
    sfMusic_setLoop(game->sound.battle, sfTrue);
}

void close_music(game_t game)
{
    sfMusic_stop(game.sound.menu_music);
    sfMusic_destroy(game.sound.menu_music);
    sfSoundBuffer_destroy(game.sound.buffer[0]);
    sfSoundBuffer_destroy(game.sound.buffer[1]);
    sfSound_destroy(game.sound.click);
    sfSound_destroy(game.sound.dye);
    sfMusic_destroy(game.sound.battle);
}