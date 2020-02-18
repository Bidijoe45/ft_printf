# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apavel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 16:07:53 by apavel            #+#    #+#              #
#    Updated: 2020/02/17 13:56:10 by apavel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c character_handler.c string_handler.c sinteger_handler.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = cc
CFLAG = -Wall -Werror -Wextra

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C ./libft/
	cp libft/libft.a ${NAME}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

libft:
	cd libft && make

test: ${NAME} libft
	gcc printf_main.c -L. -lftprintf -o printf_test

.PHONY: all clean fclean bonus re printf_test
