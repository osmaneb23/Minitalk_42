# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 17:20:48 by obouayed          #+#    #+#              #
#    Updated: 2023/12/02 17:20:48 by obouayed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_print_charstr.c ft_print_unsigned.c ft_print_hexa.c ft_print_int.c ft_print_percent.c \
		ft_print_ptr.c ft_printf.c
	

OBJS = ${SRC:.c=.o}

NAME = libftprintf.a

AR = ar rc

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

$(NAME): $(OBJS)
	$(AR) $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re