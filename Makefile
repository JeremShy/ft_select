# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:49:18 by jcamhi            #+#    #+#              #
#    Updated: 2016/03/24 20:16:34 by jcamhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c \
		   list.c \
		   print.c \
		   list_2.c \
		   signals.c \
		   list_3.c \
		   norme_pos.c \
		   boucle.c \
		   singelton.c \
		   norme_signal.c

OBJ_PATH = ./obj/

INC_PATH = ./includes

NAME = ft_select

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g

LFLAGS = -ltermcap -Llib/ -lft -lftprintf

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(NAME) : $(OBJ)
	#	make -C libsrcs/libft
	#	make -C libsrcs/ft_printf
	$(CC) $(LFLAGS) $(INC) -o $@ $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	/bin/rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	#	make -C libsrcs/libft clean
	#	make -C libsrcs/ft_printf clean

fclean: clean
	rm -fv $(NAME)
	#	make -C libsrcs/libft fclean
	#	make -C libsrcs/ft_printf fclean

re: fclean all

.PHONY : all clean fclean re
