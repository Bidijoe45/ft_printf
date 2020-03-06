/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:03:16 by apavel            #+#    #+#             */
/*   Updated: 2020/03/06 20:25:10 by apavel           ###   ########.fr       */
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
	int		printed;
	short	f_minus;
	short	f_zero;
	short	f_width;
	int		n_width;;
	short	f_star_width;
	short	f_precision;
	int		n_precision;
	short	f_star_precision;
	char	type;
	va_list	args;
}	t_flags;

/*ft_printf.c*/
int		ft_printf(const char *format, ...);
void	ft_start_flags(t_flags *flags, va_list args);
void	ft_restart_flags(t_flags *flags);
//BORRAR
void	debug_print_s_flag(t_flags *flag);
//-----

/*parse.c*/
int		ft_parse(t_flags *flags, va_list args, const char *format);

/*display.c*/
int		ft_display(t_flags *flags, char type);

/*display_c.c*/
int		ft_display_c(t_flags *flags);

/*display_s.c*/
int		ft_display_s(t_flags *flags);

/*display_int.c*/
int		ft_display_int(t_flags *flags);

/*display_u.c*/
int		ft_display_u(t_flags *flags);

/*display_x.c*/
int		ft_display_x(t_flags *flags);

/*display_p.c*/
int		ft_display_p(t_flags *flags);

/*ft_itoa_u.c*/
char	*ft_itoa_u(long n);

/*ft_itox.c*/
char	*ft_itox(unsigned long n, char type);

#endif
