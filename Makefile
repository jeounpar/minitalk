# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 12:37:47 by jeounpar          #+#    #+#              #
#    Updated: 2022/02/06 13:18:06 by jeounpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk
SERVER		= server
CLIENT		= client
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SERVER_SRC	= server_main.c
CLINET_SRC	= client_main.c
SERVER_OBJ	= server_main.o
CLIENT_OBJ	= client_main.o
PRINTF		= ./ft_printf/libftprintf.a
LIBFT		= ./ft_printf/libft/libft.a
LFLAGS		= -L./ft_printf -lftprintf -L./ft_printf/libft -lft

$(NAME)		: $(LIBFT) $(PRINTF) $(OBJECTS) $(SERVER) $(CLIENT)

all			: $(NAME)

$(SERVER)	: $(SERVER_OBJ)
	$(CC) $(SERVER_OBJ) -o $(SERVER) $(LFLAGS)

$(CLIENT)	: $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) -o $(CLIENT) $(LFLAGS)

$(PRINTF)	:
	make -C ./ft_printf

$(LIBFT)	:
	make -C ./ft_printf/libft

clean:
	make -C ./ft_printf/libft clean
	make -C ./ft_printf clean
	rm -rf $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	make -C ./ft_printf/libft fclean
	make -C ./ft_printf fclean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re: fclean all