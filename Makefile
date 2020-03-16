##
## EPITECH PROJECT, 2019
## make file
## File description:
## sdf
##

SRC	=	src/error_malloc.c	\
		src/main.c	\
		src/init_monster.c	\
		src/init_game.c	\
		src/scene/init_scene.c	\
		src/init_window.c	\
		src/init_graphic.c	\
		src/entity/init_entity.c	\
		src/button/init_button.c	\
		src/event_manager.c	\
		src/draw_manager.c	\
		src/scene/init_levels.c	\
		src/map/init_map.c	\
		src/map/draw_map.c	\
		src/map/check_map.c	\
		src/button/button_manager.c	\
		src/button/button_efect.c	\
		src/scene/start_menu/init_start_menu.c	\
		src/entity/entity_manager.c	\
		src/generic/size.c	\
		src/generic/coord.c	\
		src/generic/rotation.c	\
		src/mouse/mouse_effect.c	\
		src/mouse/manage_framebuffer.c	\
		src/generic/draw.c	\
		src/init_man.c	\
		src/waves/init_waves.c	\
		src/init_monster_bis.c	\
		src/tower/init_stat_tower.c	\
		src/monster/end_path.c	\
		src/button/button_func.c	\
		src/button/button_func_2.c	\
		src/button/button_func_3.c	\
		src/scene/start_menu/init_menu.c	\
		src/scene/start_menu/init_option.c	\
		src/scene/start_menu/init_level.c	\
		src/init_hud.c	\
		src/button/button_efect_2.c	\
		src/scene/start_menu/init_option_2.c	\
		src/hud/init_text.c	\
		src/init_audio.c	\
		src/scene/start_menu/start_menu_manager.c	\
		src/init_background.c	\
		src/scene/start_menu/init_score.c	\
		src/sort_maps_score.c	\
		src/hud/score.c	\
		src/scene/level/level_manager.c	\
		src/scene/start_menu/init_level_2.c	\
		src/scene/level/init_level_menu.c	\
		src/list/init_list.c	\
		src/list/draw_monster.c	\
		src/monster/monster_manager.c	\
		src/monster/path_finding.c	\
		src/scene/level/init_option_level.c	\
		src/tower/list.c	\
		src/tower/tower.c	\
		src/tower/angle.c	\
		src/tower/function.c	\
		src/tower/rocket.c	\
		src/tower/rocket_2.c	\
		src/scene/level/tower_menu.c	\
		src/scene/level/tower_menu_func.c	\
		src/scene/level/money_score.c	\
		src/tower/function_2.c	\
		src/tower/function_3.c

OBJ     =       $(SRC:.c=.o)

NAME    =       my_defender

LDFLAGS	=	-Llib -lmy

CFLAGS	=	-Iinclude -g -O0

CSFML	=	-l csfml-graphics -l csfml-window -l m -l csfml-system -lcsfml-audio

all:    $(NAME)


$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CSFML)

clean:
	make clean -C lib/my/
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my/
	rm -f $(NAME)

re:     fclean all

valgrind:
	make -C lib/my/
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(LDFLAGS) $(CSFML) -g
	valgrind ./$(NAME)
	rm -rf *vg
