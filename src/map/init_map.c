/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_map.c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "defense.h"
#include <unistd.h>

void fill_map(char buffer[154], char s[][15])
{
    int a = 0;
    int b = 0;

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 14 ; j++) {
            s[i][j] = buffer[i * 15 + j];
        }
        s[i][14] = 0;
    }
}

int check_map(char buffer[165])
{
    int len = 0;
    int a = 0;

    for (int i = 0; i < 164; i++)
        if (buffer[i] != '\n' && buffer[i] != '.' && buffer[i] != 'x' )
            return (1);
    for (int i = 0; i < 164; i++) {
        if (buffer[i] == '\n') {
            if (len != 14)
                return (1);
            len = 0;
            i++;
        }
        len++;
    }
    return (0);
}

int check_line(char *s, game_t *game)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] != '.' && s[i] != ' ' && s[i] != '\t' && !my_char_isnum(s[i]))
            game->scene[1].bad_file = 1;
}

map_t new_map(char buffer[588], map_t map)
{
    fill_map(buffer, map.map_number);
    if (check_road(map))
        map.good_files = 1;
    return (map);
}

map_t init_scene_lvl(char *s)
{
    map_t map;
    char str[120] = "maps/";
    my_strcpy(str + 5, s);
    map.good_files = 0;
    char buffer[165];
    int fd = open(str, O_RDONLY);
    if (fd == -1) {
        map.good_files = 1;
        send_error();
        return (map);
    }
    if (!read(fd, buffer, 165) || check_map(buffer)) {
        map.good_files = 1;
        return (map);
    }
    map = new_map(buffer, map);
    return (map);
}