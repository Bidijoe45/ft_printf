/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:49:25 by apavel            #+#    #+#             */
/*   Updated: 2020/02/23 09:04:01 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//-----BORRAR----------

void	debug_print_s_flag(t_flags *flags)
{

    printf("\n----FLAGS STRUCT----\n");
  	printf("printed: %d\n", flags->printed); 
  	printf("f_minus: %d\n", flags->f_minus); 
  	printf("f_zero: %d\n", flags->f_zero); 
  	printf("f_width: %d\n", flags->f_width);
  	printf("n_width: %d\n", flags->n_width); 
  	printf("f_star_width: %d\n", flags->f_star_width);
	printf("f_precision: %d\n", flags->f_precision);
	printf("n_precision: %d\n", flags->n_precision);
  	printf("f_star_precision: %d\n", flags->f_star_precision);
    printf("--------------------\n");
}

//---------------------

void	ft_restart_flags(t_flags *flags, va_list args)
{
	flags->printed = 0;
	flags->f_minus = 0;
	flags->f_zero = 0;
	flags->f_width = 0;
	flags->n_width = 0;
	flags->f_star_width = 0;
	flags->f_precision = 0;
	flags->n_precision = 0;
	flags->f_star_precision = 0;
	va_copy(flags->args, args);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	t_flags flags;
	int ret;

	va_start(args, format);
	i = 0;
	ret = 0;
	ret = ft_parse(&flags, args, format);
	return (ret);
}

