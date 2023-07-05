
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seroy <seroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 17:07:16 by seroy             #+#    #+#              #
#    Updated: 2023/03/15 14:16:14 by seroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Library Name ----------------------------

NAME = so_long
NAME_BONUS = so_long_bonus

#Dependencies -----------------------------

LIBFT = libft

#Command variables ------------------------

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MK = mkdir -p
RM = rm -rf
USER = $(shell whoami)
MLX42 = -framework Cocoa -framework OpenGL -framework IOKit MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib"

#Sources directories

INCDIR = inc
SRCDIR = src
LIBFT_A = libft.a
LIBFTDIR = libft
LIBFT = $(addprefix $(LIBFTDIR)/, $(LIBFT_A))
SRC = parsing.c flood_fill.c utils.c main.c render_map.c player_move.c keyhook.c load_img.c initiate.c free.c idle_img.c enemy.c enemy_move.c game_over.c putstring.c error.c
SRCB = parsing_bonus.c flood_fill_bonus.c utils_bonus.c main_bonus.c render_map_bonus.c player_move_bonus.c keyhook_bonus.c load_img_bonus.c initiate_bonus.c free_bonus.c idle_img_bonus.c enemy_bonus.c enemy_move_bonus.c game_over_bonus.c putstring_bonus.c error_bonus.c
		
VPATH = ${SRCDIR}

#Object directories

OBJDIR = obj

OBJS = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})
OBJSB = $(addprefix ${OBJDIR}/, ${SRCB:%.c=%.o})

all: $(NAME)

${OBJDIR}/%.o : %.c
	${CC} ${FLAGS} -I${INCDIR} -Ilibft/inc -Imlx42 -c $< -o $@ 
	
$(NAME): $(OBJDIR) $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) ${FLAGS} $(MLX42) $(OBJS) -L$(dir $(LIBFT)) -lft -o $(NAME)

$(OBJDIR):
	$(MK) $(OBJDIR)

$(NAME_BONUS): $(OBJDIR) $(OBJSB)
	make -C $(LIBFTDIR)
	$(CC) ${FLAGS} $(MLX42) $(OBJSB) -L$(dir $(LIBFT)) -lft -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY:
	clean fclean re bonus all