/*
** EPITECH PROJECT, 2020
** init hud
** File description:
** sfd
*/

#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "defense.h"

const char file_spec[] = "   requirements:\n\n>must be in 'maps'\nfolder\n\n>1\
1 lines\n\n>15 columns\n\n>'x' for the path\n\n>'.' for the grass";

int nb_files(char *name)
{
    DIR *dir = opendir(name);
    struct dirent *dr;
    int nb = 0;

    if (!dir)
        return (0);

    while ((dr = readdir(dir)))
        if (my_strcmp(dr->d_name, ".") && my_strcmp(dr->d_name, ".."))
            nb++;

    closedir(dir);
    return (nb);
}

char **get_maps(void)
{
    DIR *dir = opendir("maps");
    struct dirent *dr;
    int nb = nb_files("maps");
    char **tab = malloc(sizeof(char *) * (nb + 1));

    if (!dir || !tab || !nb)
        return (NULL);

    tab[nb] = NULL;

    for (int i = 0, j = 0; (dr = readdir(dir)) ; i++)
        if (my_strcmp(dr->d_name, ".") && my_strcmp(dr->d_name, ".."))
            tab[j++] = my_strdup(dr->d_name);
    sort_maps(tab);
    closedir(dir);
    return (tab);
}

void init_texts(game_t *game)
{
    game->hud.music_lvl = new_text(nbstr((int)game->sound.lvl_music), game);
    my_strcpy(game->hud.music_lvl.relative, "bar_music_option_start");
    game->hud.music_lvl.entity.transform.coord.x = 0;
    game->hud.music_lvl.entity.transform.coord.y = -100;
    game->hud.scor = new_text("0", game);
    game->hud.money = new_text("250", game);
    game->hud.scor.entity.transform.coord = (sfVector2f){400, 50};
    game->hud.money.entity.transform.coord = (sfVector2f){-400, 50};
    my_strcpy(game->hud.scor.relative, "menu_tower");
    my_strcpy(game->hud.money.relative, "menu_tower");
}

void fill_files(game_t *game)
{
    int len = -1;

    while (game->hud.files_c[++len]);

    game->hud.files = malloc(sizeof(text_t) * (len + 1));
    game->hud.files[len].text = NULL;
    game->hud.file_selector = 0;

    for (int i = 0; game->hud.files_c[i] ; i++) {
        game->hud.files[i] = new_text(game->hud.files_c[i], game);
        game->hud.files[i].entity.transform.coord.x = 0;
        game->hud.files[i].entity.transform.coord.y = -160;
        my_strcpy(game->hud.files[i].relative, "level_start");
    }
}

void init_hud(game_t *game)
{
    game->hud.files_c = get_maps();
    game->hud.font = sfFont_createFromFile("sprites/font.ttf");
    if (!game->hud.files_c)
        game->hud.files = NULL;
    else
        fill_files(game);
    game->hud.error_file = new_text("No files", game);
    game->hud.file_spec = new_text(file_spec, game);
    game->hud.fps = new_text("fps :", game);
    game->hud.fps_option = new_text("fps", game);
    game->hud.wave = new_text("Wave ", game);
    game->hud.wave.entity.transform.coord = (sfVector2f){600, 450};
    init_hud_file(game);
    init_text_score(game);
    sfText_setColor(game->hud.fps.text, sfYellow);
    sfText_setColor(game->hud.file_spec.text, sfRed);
    my_strcpy(game->hud.error_file.relative, "level_start");
    my_strcpy(game->hud.file_spec.relative, "level_start");
    my_strcpy(game->hud.fps_option.relative, "option_start");
    init_texts(game);
}