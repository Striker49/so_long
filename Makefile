
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
CFLAGS = -Wall -Wextra -Werror
MK = mkdir -p
RM = rm -rf
# MLX42 = -framework Cocoa -framework OpenGL -framework IOKit

#Sources directories

INCDIR = inc
SRCDIR = src
LIBFT_A = libft.a
LIBFTDIR = libft
LIBFT = $(addprefix $(LIBFTDIR)/, $(LIBFT_A))
SRC = parsing.c utils.c	main.c
		
VPATH = ${SRCDIR}

#Object directories

OBJDIR = obj

OBJS = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})

${OBJDIR}/%.o : %.c
	${CC} ${FLAGS} -I${INCDIR} -Ilibft/inc -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) ${FLAGS}  $(OBJS) -L$(dir $(LIBFT)) -lft -o $(NAME)
# ajouter ${MLX42}

$(OBJDIR):
	$(MK) $(OBJDIR)

clean:
	$(RM) $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all