# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sofernan <sofernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 13:48:03 by sofernan          #+#    #+#              #
#    Updated: 2024/08/05 18:24:33 by sofernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar rcs

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_putchar.c ft_printf.c ft_putstr.c \
       ft_print_ptr.c \
       ft_putnbr.c ft_print_unsigned.c	ft_print_hex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
