/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:11:42 by apavel            #+#    #+#             */
/*   Updated: 2020/02/25 19:04:15 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_display_width(t_flags *flags, char *num)
{
	int i;
	char empty_char;
	int ret;

	empty_char = (flags->f_zero && flags->f_precision == 0) ? '0' : ' ';
	i = 0;
	if (flags->f_width == 1)
	{
		//printf("w_Width: %lu \n", flags->n_width - ft_strlen(num));
		if (flags->f_precision == 1 && flags->n_precision > ft_strlen(num))
		{
			if (num[0] == '-')
				i++;
			while (i++ < flags->n_width - ft_strlen(num) - (flags->n_precision -  ft_strlen(num)))
				ret += write(1, &empty_char, 1);
		}
		else
			while (i++ < flags->n_width - ft_strlen(num))
				ret += write(1, &empty_char, 1);
	}
	printf("ft_display_width ret: %d\n", ret);
	return (ret);
}

int		ft_display_precision(t_flags *flags, char *num)
{
	int i;
	int ret;
	
	ret = 0;
	if (flags->n_precision > ft_strlen(num))
	{
		if (num[0] == '-')
			write(1, "-", 1);
		i = 0;
		if (num[0] == '-')
		{
			num++;
			while (i++ < flags->n_precision - ft_strlen(num))
				ret += write(1, "0", 1);
		}
		else
		{
			while (i++ < flags->n_precision - ft_strlen(num))
				ret += write(1, "0", 1);
		}
	}
	printf("ft_display_precision ret: %d\n", ret);
	return (ret);
}

void	ft_display_int_inverse(t_flags *flags)
{
	write(1, "INVERSE\n", 8);
}

int		ft_display_int(t_flags *flags)
{
	int ret;
	char *num;
	
	ret = 0;
	num = ft_itoa(va_arg(flags->args, int));
	if (flags->f_minus == 1)
		ft_display_int_inverse(flags);
	else
	{
		if (num[0] == '-' && flags->f_precision == 0 && flags->f_zero == 1)
			ret += write(1, "-", 1);
		ret += ft_display_width(flags, num);
		ret += ft_display_precision(flags, num);
	}
	if (num[0] == '-')
	{
		num++;
		ret = write(1, num, ft_strlen(num));
		free(--num);
	}
	else
	{
		ret = write(1, num, ft_strlen(num));
		free(num);
	}
	printf("ret: %d\n", ret);
	return (flags->printed);
}
