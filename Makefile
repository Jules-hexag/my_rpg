##
## EPITECH PROJECT, 2022
## makefile
## File description:
## build the project
##

SRC			=	src/main.c \
				src/rpg.c \
				src/rpg_loop.c \
				src/bars/init_bars.c \
				src/bars/render_bars.c \
				src/bars/update_bars.c \
				src/binary_heap/binary_heap.c \
				src/binary_heap/binary_heap2.c \
				src/enemies/init_enemy.c \
				src/enemies/render_enemy.c \
				src/enemies/update_enemy.c \
				src/errors/check_exec_errors.c \
				src/events/start_menu_evts/hover_colorization.c \
				src/game/manage_game_events.c \
				src/game/render_game.c \
				src/game/update_game.c \
				src/game/init_game.c \
				src/instance/destroy_instance.c \
				src/instance/init_instance.c \
				src/instance/update_instance.c \
				src/inventory/init_inventory.c \
				src/map/destroy_map.c \
				src/map/init_map.c \
				src/map/render_map.c \
				src/map/vertex_operations.c \
				src/particle/create_rain.c \
				src/particle/display_rain.c \
				src/pause_menu/pause_menu_funcs/buttons_funcs.c \
				src/pause_menu/init_pause_menu.c \
				src/pause_menu/manage_pause_menu_events.c \
				src/pause_menu/render_pause_menu.c \
				src/pause_menu/update_pause_menu.c \
				src/player/attack_zombies.c \
				src/player/init_player.c \
				src/player/render_player.c \
				src/player/update_player.c \
				src/settings/init_settings.c \
				src/settings/manage_settings_events.c \
				src/settings/render_settings.c \
				src/settings/settings_functions/buttons_funcs.c \
				src/settings/settings_functions/volume/init_volume.c \
				src/settings/settings_functions/volume/render_volume.c \
				src/settings/settings_functions/volume/update_volume.c \
				src/settings/update_settings.c \
				src/start_menu/start_menu_funcs/buttons_funcs.c \
				src/start_menu/init_start_menu.c \
				src/start_menu/manage_start_menu_events.c \
				src/start_menu/render_start_menu.c \
				src/start_menu/update_start_menu.c \
				src/tutorial/manage_tutorial_events.c \
				src/tutorial/render_tutorial.c \
				src/tutorial/update_tutorial.c \
				src/utils/gen_shapes.c \
				src/utils/init_text.c \
				src/utils/my_strncmp.c \
				src/window/init_window.c \
				src/my_itoa.c \
				src/my_strcat.c \

TESTS_SRC	=	bonus/tests.c \

OBJ			=	$(SRC:.c=.o)

DEP			=	$(SRC:.c=.d)

T_OBJ		=	$(TESTS_SRC:.c=.o)

NAME		=	my_rpg

TESTS		=	unit_tests

## LIB 	=		lib/libmy.a

## LDFLAGS = 	-L./lib

LDLIBS		=	-lcriterion -lcsfml-graphics -lcsfml-window -lcsfml-system \
				-lcsfml-audio -lm
## -lmy

CC			=	gcc

RM			=	rm -rvf

CPPFLAGS	=	-I./include -MMD -MP

CFLAGS		=	-Wall -Wextra -std=gnu2x

CFLAGS_DEBUG	=	-I./include -ggdb3

CFLAGS_TESTS	=	-I./include/ -ggdb3 -O0 --coverage


$(NAME) : $(OBJ) ##$(LIB)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDLIBS)

-include $(DEP)

all : $(NAME)

## $(LDFLAGS)

$(TESTS): CFLAGS=$(CFLAGS_TESTS)
$(TESTS): re $(T_OBJ)
	@$(CC) -o $@ $(T_OBJ) $(CFLAGS) $(LDLIBS)
## $(LDFLAGS)

## $(LIB):
##	make -C lib/my/

debug: CFLAGS=$(CFLAGS_DEBUG)
debug: re

clean:
	@$(RM) $(OBJ)
	@$(RM) $(T_OBJ)
	@$(RM) $(TESTS)
	@$(RM) $(DEP)

tests_run: ## $(TESTS)
##	./$(TESTS) --always-succeed
##	gcovr --exclude bonus/tests.c
##	gcovr --branches --exclude bonus/tests.c

fclean: clean
	@$(RM) $(NAME)
## make fclean -C lib/my/

re: fclean all

.PHONY: all clean fclean re tests_run unit_tests
