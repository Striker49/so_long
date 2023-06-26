
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
SRC = parsing.c flood_fill.c utils.c main.c render_map.c player_move.c keyhook.c load_img.c initiate.c free.c idle_img.c enemy.c enemy_move.c game_over.c putstring.c
SRCB = parsing.c flood_fill.c utils.c main.c render_map_bonus.c player_move_bonus.c keyhook.c load_img.c initiate.c free.c idle_img.c enemy.c enemy_move.c game_over.c putstring.c
		
VPATH = ${SRCDIR}

#Object directories

OBJDIR = obj

OBJS = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})
OBJSB = $(addprefix ${OBJDIR}/, ${SRCB:%.c=%.o})

${OBJDIR}/%.o : %.c
	${CC} ${FLAGS} -I${INCDIR} -Ilibft/inc -Imlx42 -c $< -o $@ 
	
all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) ${FLAGS} $(MLX42) $(OBJS) -L$(dir $(LIBFT)) -lft -o $(NAME)

$(OBJDIR):
	$(MK) $(OBJDIR)

bonus: $(OBJDIR) $(OBJSB)
	make -C $(LIBFTDIR)
	$(CC) ${FLAGS} $(MLX42) $(OBJSB) -L$(dir $(LIBFT)) -lft -o $(NAME)

clean:
	$(RM) $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all