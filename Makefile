##
## EPITECH PROJECT, 2022
## makefile
## File description:
## build the project
##

SRC			=	src/main.c \
				src/rpg.c \
				src/errors/check_exec_errors.c \
				src/map/map.c \
				src/map/objects.c \
				src/window/create_window.c \
				src/game_loop.c \
				src/map/display_map.c \
				src/events/main_evts.c \
				src/utils/free_arrays.c \
				src/map/gen_map_tab.c \
				src/my_strncmp.c

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

CFLAGS		=	-O2 -Wall -Wextra -std=c2x

CFLAGS_DEBUG	=	-I./include -ggdb3 -fsanitize=address

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
