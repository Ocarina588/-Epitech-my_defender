/*
** EPITECH PROJECT, 2020
** text coord
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "defense.h"
#include "button.h"

text_t new_text(const char *str, game_t *game)
{
    text_t text = {.entity = new_entity(), .text = sfText_create()};
    float len = 0;
    float a;
    if (!text.text)
        return ((text_t){0});
    my_strcpy(text.str, str);
    sfText_setString(text.text, str);
    sfText_setFont(text.text, game->hud.font);
    sfText_setColor(text.text, sfWhite);
    sfText_setOutlineThickness(text.text, 2);
    sfText_setOutlineColor(text.text, sfBlack);
    a = (float)sfText_getCharacterSize(text.text);
    len += sfText_getLineSpacing(text.text) * (my_strlen(str) - 1);
    len += a * my_strlen(str);
    text.entity.transform.size.x = len;
    text.entity.transform.size.y = a;
    for (int i = 0; i < 64 ; i++)
        text.relative[i] = 0;
    sfText_setOrigin(text.text, (sfVector2f){len / 2, a / 2});
    return (text);
}

void update_text(game_t *game, text_t text)
{
    sfVector2u original = {1, 1};
    transform_t transform = text.entity.transform;
    float a = (float)sfText_getCharacterSize(text.text);
    float len = (my_strlen(text.str) - 1);
    len += a * my_strlen(text.str);

    transform.scale.x = transform.size.x / len;
    transform.scale.y = transform.size.y / a / 2;
    sfText_setScale(text.text, transform.size);

    sfText_setString(text.text, text.str);
    sfText_setPosition(text.text, text.entity.transform.coord);
    sfText_setRotation(text.text, text.entity.transform.rotation);
    sfText_setScale(text.text, text.entity.transform.scale);
}

void update_coord_text(game_t *game, text_t text)
{
    button_t parent;
    int rep = 1;

    while (1) {
        if (rep ? *text.relative : *parent.relative) {
            parent = *get_button(rep ? text.relative : parent.relative);
            text.entity.transform.coord.x += parent.entity.transform.coord.x;
            text.entity.transform.coord.y += parent.entity.transform.coord.y;
            rep = 0;
        } else
            break;
    }
    update_text(game, text);
}

void init_hud_file(game_t *game)
{
    game->hud.error_file.entity.transform.coord = (sfVector2f){0, -160};
    game->hud.file_spec.entity.transform.coord = (sfVector2f){970, -105};
    game->hud.file_spec.entity.transform.scale =  (sfVector2f){0.7, 0.7};
    game->hud.fps.entity.transform.coord =  (sfVector2f){80, 30};
    game->hud.fps_option.entity.transform.coord =  (sfVector2f){-170, 80};
}

void draw_text(text_t text)
{
    game_t *game = gg();
    update_coord_text(game, text);
    sfRenderWindow_drawText(game->window.render, text.text, NULL);
}