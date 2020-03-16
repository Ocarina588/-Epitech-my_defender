/*
** EPITECH PROJECT, 2020
** essentiel
** File description:
** sdf
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Audio.h>

#ifndef ESSENTIEL_H
#define ESSENTIEL_H

#define NB_SCENE (2)
#define NB_TOWER (17)
#define NB_BUTTON (79)

#define NB_BUTTON_START_MENU (40)
#define NB_BUTTON_LEVEL (28)
#define NB_BUTTON_MAX (40)

#define LEN (100)
#define HP_W (25)
#define HP_H (3)

extern const int nb_button_scene[NB_SCENE];

typedef enum tower
{
    sniper,
    basic,
    poison,
    trap
} tower;

typedef enum button_selector
{
    b_start = 45,
    b_play,
    b_pause,
    b_next,
    b_menu,
    b_back,
    b_shop,
    b_reset,
    b_buy,
    b_rate,
    b_mute,
    b_quit,
    b_yes,
    b_no,
    b_ok,
    b_on,
    b_off,
    b_new_game,
    b_continue,
    b_options,
    b_resume,
    b_levels,
    b_about,
    b_score,
    b_volume,
    b_wood_bar,
    b_wood_square,
    b_wood_rect,
    t_wall,
    t_sniper,
    t_basic,
    t_poison,
    t_slow
} button_selector;

typedef enum scene_selector
{
    start_menu,
    level
} scene_selector;

typedef enum tower_selector
{
    ball_yellow,
    ball_brown,
    ball_grey,
    fire_1,
    fire_2,
    fire_3,
    fire_4,
    rocket_small,
    rocket_big,
    platform,
    tower_green,
    tower_red,
    tower_grey_without_rocket,
    tower_grew_with_rocket,
    tower_poison,
    tower_slow,
    slow
} tower_selector;

typedef struct transform_t
{
    sfVector2f coord;
    sfVector2f scale;
    sfVector2f size;
    float rotation;
} transform_t;

typedef struct motion_t
{
    sfVector2f velocity;
    sfVector2f acceleration;
} motion_t;

typedef struct animation_t
{
    int actual_frame;
    int nb_frame;
    sfSprite **sprite;
} animation_t;

typedef struct entity_t
{
    sfSprite *sprite;
    char name[64];
    struct transform_t transform;
    struct motion_t motion;
    struct animation_t animation;
} entity_t;

typedef struct button_t
{
    struct entity_t entity;
    sfSprite *sprite;
    char relative[64];
    int clicked;
    int activated;
    sfVector2f interval;
    size_t offset;
    sfVector2f move;
    sfVector2f speed;
    void (*function)(void *, ...);
    void (*hover)(void *, ...);
    void (*normal)(void *, ...);
    void (*click)(void *, ...);

} button_t;

typedef struct tim_t
{
    float dt;
    sfClock *clock;
    long int realesed_time;
    int double_clicked;
    long int old_time;
} tim_t;

typedef struct window_t
{
    sfRenderWindow *render;
    sfVideoMode mode;
    sfEvent event;
    tim_t time;
    int fps;
    int pause;
    int len_tile;
} window_t;

typedef struct wave_t
{
    int nb_waves;
    int index;
    int nb_monster;
    int stop;
    int time;
    int check;
    int check2;
    int nb;
} wave_t;

typedef struct framebuffer {
    unsigned int x;
    unsigned int y;
    sfUint8  *pixels;
    sfSprite *mouse;
    sfTexture *mouse_tex;
} framebuffer_t;

typedef struct sound_t
{
    float lvl_music;
    sfMusic *battle;
    sfSoundBuffer *buffer[2];
    sfSound *click;
    sfSound *dye;
    sfMusic *menu_music;
} sound_t;

typedef struct malus_t
{
    int poison;
    int frozen;
    float time;
} malus_t;

typedef struct monster_t
{
    float index;
    struct entity_t entity;
    int life;
    float speed;
    int max_life;
    int modulo;
    int coord;
    struct malus_t malus;
    int mo;
    struct tower_t *tower;
    struct monster_t *next;
} monster_t;

typedef struct rocket_t
{
    struct entity_t entity;
    sfSprite *sprite;
    int damage;
    int poison;
    struct monster_t *monster;
    struct rocket_t *next;
    float speed;
} rocket_t;

typedef struct info_tower_t
{
    int type;
    int damage;
    float time;
    float time_spend;
    int level;
    float radius;
} info_tower_t;

typedef struct tower_t
{
    struct monster_t *monster;
    struct tower_t *next;
    struct rocket_t *rocket;
    float angle_base;
    struct info_tower_t stat;
    sfSprite *sprite;
    struct entity_t entity;
} tower_t;

typedef struct plug_t
{
    struct tower_t *tower;
    tower type;
    sfRectangleShape *life[2];
    struct rocket_t *rocket;
    sfCircleShape *circle;
    int right_click;
    sfRectangleShape *rec;
} plug_t;

typedef struct text_t
{
    sfText *text;
    char str[1024];
    entity_t entity;
    char relative[64];
} text_t;

typedef struct hud_t
{
    char **files_c;
    int how_i;
    text_t error_file;
    text_t music_lvl;
    text_t how[3];
    text_t score[3][2];
    text_t file_spec;
    text_t fps;
    text_t scor;
    text_t wave;
    text_t money;
    text_t fps_option;
    int file_selector;
    text_t *files;
    sfFont *font;
} hud_t;

typedef struct graphic_t
{
    sfTexture **tower;
    sfTexture *tex_heart;
    sfSprite *heart;
    sfTexture *elephant[15];
    sfTexture *fox[6];
    sfTexture *man[7];
    sfSprite **animals[3];
    sfTexture *map[8];
    sfSprite *road[8];
    sfSprite *background[8];
    sfTexture *button[NB_BUTTON];
} graphic_t;

typedef struct scene_t
{
    struct monster_t *monster;
    struct info_tower_t stat[4];
    int bad_file;
    struct plug_t plug;
    struct button_t button[NB_BUTTON_MAX];
} scene_t;

typedef struct map_t
{
    char map_number[11][15];
    int good_files;
    sfVector2f *coord_tab;
} map_t;

typedef struct game_t
{
    struct sound_t sound;
    struct hud_t hud;
    struct map_t *map;
    struct wave_t wave;
    struct graphic_t graphic;
    struct scene_t scene[NB_SCENE];
    struct window_t window;
    int score;
    int money;
    int lose;
    enum scene_selector actual_scene;
} game_t;

#endif /* !ESSENTIEL_H */
