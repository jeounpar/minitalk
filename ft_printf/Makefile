# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 00:17:39 by jeounpar          #+#    #+#              #
#    Updated: 2021/11/17 00:17:41 by jeounpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
	ft_printf_format.c \
	ft_printf_utils.c \
	ft_printf_pointer.c

OBJECTS = $(SRCS:.c=.o)


$(NAME) : $(OBJECTS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	ar rcs $(NAME) $(OBJECTS)

bonus :

all : $(NAME)

clean :
	make -C $(LIBFTDIR) clean
	rm -f $(OBJECTS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re bonus
