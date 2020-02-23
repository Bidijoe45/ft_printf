/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:11:42 by apavel            #+#    #+#             */
/*   Updated: 2020/02/23 09:03:47 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zero(int n)
{
	return ((n < 0) ? 0 : n);
}

int		ft_display_int_inverse(t_flags *flags, char *num, char empty_char)
{
	int i;
	i = 0;
	if (flags->n_precision <= ft_strlen(num))
	{
		write(1, num, ft_strlen(num));
		while (i++ < zero(flags->n_width - ft_strlen(num)))
			write(1, &empty_char, 1);
	}
	else
	{		
		while (i++ < flags->n_precision - ft_strlen(num))
			write(1, "0", 1);
		i = 0;
		write(1, num, ft_strlen(num));
		while (i++ < flags->n_width - ((flags->n_precision - ft_strlen(num)) + ft_strlen(num)))
			write(1, &empty_char, 1);
	}
	return (0);
}

int		ft_display_int(t_flags *flags)
{
	int		i;
	char	*num;
	char	empty_char;
	i = 0;
	num = ft_itoa(va_arg(flags->args, int));
	empty_char = (flags->f_zero == 1 && flags->f_precision == 0) ? '0' : ' ';
	if (flags->f_minus == 1)
		ft_display_int_inverse(flags, num, empty_char);
	else if (flags->n_precision <= ft_strlen(num))
	{
		write(1, "Entra1\n", 6);
		while (i++ < zero(flags->n_width - ft_strlen(num)))
			write(1, &empty_char, 1);
	}
	else
	{
		write(1, "Entra2\n", 6);
		while (i++ < flags->n_width - ((flags->n_precision - ft_strlen(num)) + ft_strlen(num)))
			write(1, &empty_char, 1);
		i = 0;
		while (i++ < flags->n_precision - ft_strlen(num))
			write(1, "0", 1);
	}
	write(1, num, ft_strlen(num));
	//printf("\nI %d\n", i);
	flags->printed = i;
	free(num);
	return (0);
}
