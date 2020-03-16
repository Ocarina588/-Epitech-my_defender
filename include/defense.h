/*
** EPITECH PROJECT, 2020
** defense
** File description:
** sdf
*/

#ifndef sdf
#define sdf

#include "essentile.h"

void close_music(game_t game);

void setup_menu_start(game_t *game);
void setup_option_start(game_t *game, scene_selector scene, char *name);
void setup_level_start(game_t *game);
void setup_score_start(game_t *game);
void corner_option(scene_selector scene);
void setup_option_level(game_t *game);
void go_option_menu_level(void *arg, ...);
void bar_music_level(game_t *game, scene_selector scene);

#define update(X) _Generic((X), button_t *: update_button, monster_t * : \
update_monster, tower_t * : update_tower, rocket_t * : update_rocket)(X)
#define set_size(X, w, h) _Generic((X), button_t : button_size)(&X, w, h)
#define set_coord(X, x, y) _Generic((X), button_t : button_coord)(&X, x, y)
#define set_rotation(X, a) _Generic((X), button_t : button_rotation)(&X, a)
#define draw(X) _Generic((X), text_t : draw_text, button_t : draw_button, \
monster_t * : draw_monster, tower_t * : draw_tower, rocket_t * : draw_rocket)(X)

void button_coord(button_t *button, float x, float y);
void button_size(button_t *button, float w, float h);
void button_rotation(button_t *button, float a);
void quit(void *arg, ...);
void init_hud_file(game_t *game);
int check_error(void);
void send_error(void);

void init_text_score(game_t *game);
void init_sound(game_t *game);
void init_background(graphic_t *graphic);
game_t init_game(void);
void init_hud(game_t *game);
window_t init_window(void);
void init_scene(game_t *game);
graphic_t init_graphic(void);
void event_manager(game_t *game);
void my_defender(game_t *game);
void draw_scene(game_t *game);
void draw_background(game_t *game);

entity_t new_entity(void);

void init_start_menu(game_t *game);
void init_level_menu(game_t *game);
void draw_buttons(game_t *game);

void explosion_effect(game_t *game);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

game_t *get_game(int mode, game_t *game);
game_t *gg(void);

void button_manager(game_t *game, int mode);
button_t *get_button(char *name);
void update_button(button_t *button);
int is_in_button(button_t button);
void draw_button(button_t button);
void draw_text(text_t text);
void button_coord(button_t *button, float x, float y);
void button_size(button_t *button, float w, float h);
void normal_effect(void *arg, ...);
void hover_effect(void *arg, ...);
void click_effect(void *arg, ...);
void rot_right(void *arg, ...);
void rot_left(void *arg, ...);
void hover_gray(void *arg, ...);
void go_to_score(void *arg, ...);

float get_mouse_pos_button(button_t *button, game_t *game);

void bar_music(game_t *game, scene_selector scene);
void set_dark_pause(game_t *game);
text_t new_text(const char *str, game_t *game);
void update_coord_text(game_t *game, text_t text);
int nb_files(char *name);
map_t init_scene_lvl(char *s);
int init_levels(game_t *game);
void draw_menu(game_t *game);
void sort_maps(char **map);
int read_score(game_t *game);

void play_button(game_t *game);
void draw_level(game_t *game);
int draw_map(int index, int x, int y, float scale);
void what_sprite_draw(sfVector2i pos, int x, int y, float scale);
void what_turn_draw(sfVector2i pos, int x, int y, float scale);
void what_turn_drawbis(sfVector2i pos, int x, int y, float scale);
void what_turn_drawter(sfVector2i pos, int x, int y, float scale);
void draw_last_turn(sfVector2i pos, int x, int y, float scale);
int check_road(map_t map);
sfSprite **init_elephant(graphic_t *graphic);
void push_node(monster_t *monster, game_t *game);
monster_t *new_monster(int i);
monster_t *new_elephant(void);
monster_t *new_fox(void);
void move_monster(monster_t *monster);
void update_entity(sfSprite *sprite, entity_t entity);
void update_monster(monster_t *monster);
void draw_monster(monster_t *monster);
void draw_monst(game_t *game);
void monster_manager(game_t *game);
int begin_road(game_t *game, int k);
sfVector2f *init_tab_coord(game_t *game, int i);
int algo_path_finding(game_t *game, monster_t *m);
void end_path(monster_t *m, sfVector2i pos, sfVector2f res, map_t map);
void restart_level(game_t *game);
int set_text_wave(int mode, game_t *game);
void new_ele_bis(monster_t *new);
void new_fox_bis(monster_t *new);
void set_up_rec(sfIntRect *rec, int i, int, int);
void init_stat_tower(game_t *game);
int check_line(char *s, game_t *game);
void set_up_rec_bis(sfIntRect *rec, int i, int height, int top);

void defreez(monster_t *monster, game_t *game);
void how_to_play(game_t *game);
static void go_menu(void *arg, ...);
int youlose(game_t *game);

void init_how(game_t *game);
void init_waves(game_t *game);
int gestion_waves(game_t *game);

void update_tower(tower_t *tower);
void draw_tower(tower_t *tower);
void draw_tow(game_t *game);
void push_tower(tower_t *tower, game_t *game);
void erase_tower(game_t *game, tower_t *a);
tower_t *new_tower(game_t *game, sfVector2f coord,
    float angle);
float compute_angle(tower_t *tower);
float get_distance(sfVector2f a, sfVector2f b);
void find_and_check_monster(game_t *game, tower_t *tower);
void tower_manager(game_t *game);
sfVector2f get_direction_vector(tower_t *tower);
void update_rotation_tower(tower_t *tower);
void add_tower(game_t *game);
int check_good_pos(game_t *game, sfVector2i m);
int end_road(game_t *game, int k);
sfSprite **init_fox(graphic_t *graphic);
void update_rocket(rocket_t *rocket);
void draw_rocket(rocket_t *rocket);
void draw_rock(game_t *game);
void push_rocket(rocket_t *rocket, game_t *game);
void erase_rocket(game_t *game, rocket_t *a);
rocket_t *new_rocket(game_t *game, tower_t *tower, int type);
sfVector2f get_direction_rocket(rocket_t *rocket);
float compute_angle_rocket(rocket_t *rocket);
float scalar_product(sfVector2f u, sfVector2f v);
float vector_norm(sfVector2f u);
void remove_m(monster_t *a, game_t *game);
int check_target(rocket_t *rocket);
void rocket_manager(game_t *game);
void set_rocket_speed(rocket_t *rocket);
sfSprite **init_man(graphic_t *graphic);
monster_t *new_man(void);
void change_orientation(monster_t *m, sfVector2f res, game_t *game);
void setup_chose_tower(game_t *game);
void slow_monster(game_t *game, tower_t *tower);
tower_t *check_if_exit(game_t *game, sfVector2i coord);
int is_near_map(game_t *game, int y, int x);
void draw_gride(game_t *game);
void money_score(game_t *game);
void update_realesed_time(game_t *game);
void sell_tower(game_t *game);
void upgrade_tower(game_t *game);
void write_score(game_t *game);
void quite_game(game_t *game);
void quit_game_in_level(void *arg, ...);

void choose_poison(void *arg, ...);
void choose_sniper(void *arg, ...);
void choose_basic(void *arg, ...);
void choose_trap(void *arg, ...);

#endif