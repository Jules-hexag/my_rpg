##
## EPITECH PROJECT, 2022
## makefile
## File description:
## build the project
##

SRC			=	src/rpg.c \
				src/main.c \
				src/rpg_loop.c \
				src/map/init_map.c \
				src/map/render_map.c \
				src/bars/init_bars.c \
				src/map/destroy_map.c \
				src/game/render_game.c \
				src/bars/render_bars.c \
				src/game/update_game.c \
				src/utils/gen_shapes.c \
				src/utils/my_strncmp.c \
				src/events/game_evts.c \
				src/utils/free_arrays.c \
				src/player/init_player.c \
				src/window/init_window.c \
				src/player/render_player.c \
				src/map/vertex_operations.c \
				src/instance/init_instance.c \
				src/game/manage_game_events.c \
				src/errors/check_exec_errors.c \
				src/instance/destroy_instance.c \
				src/start_menu/init_start_menu.c \
				src/start_menu/start_menu_loop.c \
				src/events/start_menu_evts/start_evts.c \
				src/events/start_menu_evts/click_management.c \
				src/events/start_menu_evts/hover_colorization.c \
				src/events/start_menu_evts/check_mouse_coords.c \
				src/events/start_menu_evts/mouse_evt_management.c \
				src/bars/update_bars.c \
				src/player/update_player.c \

TESTS_SRC	=	bonus/tests.c \

OBJ			=	$(SRC:.c=.o)

DEP			=	$(SRC:.c=.d)

T_OBJ		=	$(TESTS_SRC:.c=.o)

NAME		=	my_rpg

TESTS		=	unit_tests

## LIB 	=		lib/libmy.a

## LDFLAGS = 	-L./lib

LDLIBS		=	-lcriterion -lcsfml-graphics -lcsfml-window -lcsfml-system
## -lmy

CC			=	gcc

RM			=	rm -rvf

CPPFLAGS	=	-I./include -MMD -MP

CFLAGS		=	-Wall -Wextra -std=c2x

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
