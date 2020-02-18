/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:03:16 by apavel            #+#    #+#             */
/*   Updated: 2020/02/18 18:53:49 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_printf_H
# define ft_printf_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "libft/libft.h"

typedef struct Format
{
	short	minus;
	short	zero;
	int		n;
	short	star;
}	Format;

/*ft_printf.c*/
int		ft_printf(const char *format, ...);

/*character_hanndler.c*/
int		character_handler(int c);

/*string_handler.c*/
int		string_handler(const char *str);

/*sinteger_handler.c*/
int		sinteger_handler(int num);

/*format_parser.c*/
char	get_datatype(const char *format);
int		parse_flags(const char *format, Format *s_format);
int		get_flags(const char *format, Format *s_format);
int		get_width(const char *format, Format *s_format);

#endif
