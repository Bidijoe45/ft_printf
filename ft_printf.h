/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:03:16 by apavel            #+#    #+#             */
/*   Updated: 2020/02/21 15:05:19 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_printf_H
# define ft_printf_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "libft/libft.h"

//------BORRAR----
# include <stdio.h>
//----------------

typedef struct s_flags
{
	int		i;
	short	f_minus;
	short	f_zero;
	short	f_width;
	int		n_width;;
	short	f_star_width;
	short	f_precision;
	int		n_precision;
	short	f_star_precision;
	va_list	args;
}	t_flags;

/*ft_printf.c*/
//BORRAR
void	debug_print_s_flag(t_flags *flag);
//-----
int		ft_printf(const char *format, ...);

/*parse.c*/
int		ft_parse(t_flags *flags, const char *format);

/*display.c*/
int		ft_display(t_flags *flags, char type);

/*display_c.c*/
int		ft_display_c(t_flags *flags);

#endif
