##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	source/menu.c				\
		source/play_background_music.c		\
		source/menu_textures.c			\
		source/my_runner.c			\
		source/get_tick.c			\
		source/get_movement_tick.c		\
		source/set_game_background.c		\
		source/set_game_ground.c		\
		source/set_game_spikes.c		\
		source/draw_all_game_sprites.c		\
		source/draw_spikes.c			\
		source/sea_texture.c			\
		source/move_sea.c			\
		source/move_background.c		\
		source/move_ground.c			\
		source/move_spikes.c			\
		source/tile_2_texture.c			\
		source/sonic_animations.c		\
		source/print_description.c		\
		source/jump.c				\
		source/death.c				\
		source/game_over.c

NAME	=	my_runner

LIB_MY	=	libmy.a

CSFLAGS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

all:	binary

$(LIB_MY):
		make -sC lib/my/

binary:	$(LIB_MY)
		gcc -o $(NAME) $(SRC) main.c -I./include -L./lib -lmy -lm $(CSFLAGS)

clean:
		make -sC lib/my/ clean
		$(shell find -name "*.gcda" -delete)
		$(shell find -name "*.gcno" -delete)
		$(shell find -name "#*#" -delete -o -name "*~" -delete)

fclean:	clean
		make -sC lib/my/ fclean
		rm -f $(NAME)
		rm -f unit_test
		clear

re:	fclean all

.PHONY:	clean fclean re all
