# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apavel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 16:07:53 by apavel            #+#    #+#              #
#    Updated: 2020/03/06 16:24:29 by apavel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c parse.c display.c display_c.c display_int.c display_s.c display_u.c ft_itoa_u.c display_x.c ft_itox.c display_p.c
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
	gcc ${FLAGS} printf_main.c -g -L. -lftprintf -o printf_test

.PHONY: all clean fclean bonus re printf_test
