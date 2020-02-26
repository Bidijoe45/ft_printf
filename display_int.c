/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:11:42 by apavel            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:28 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_display_width(t_flags *flags, char *num)
{
	int i;
	char empty_char;
	int ret;
	
	ret = 0;
	empty_char = (flags->f_zero && flags->f_precision == 0) ? '0' : ' ';
	i = 0;
	if (flags->f_width == 1 && flags->n_width > ft_strlen(num))
	{
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
			ret += write(1, "-", 1);
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
	return (ret);
}

void	ft_display_int_inverse(t_flags *flags, char *num)
{

	flags->printed += ft_display_precision(flags, num);
		
	if (num[0] == '-' && flags->f_zero == 1)
	{
		num++;
		flags->printed += write(1, num, ft_strlen(num));
		free(--num);
	}
	else
	{
		flags->printed += write(1, num, ft_strlen(num));
		free(num);
	}
	flags->printed += ft_display_width(flags, num);

}

int		ft_display_int(t_flags *flags)
{
	int ret;
	char *num;
	
	ret = 0;
	num = ft_itoa(va_arg(flags->args, int));
	if (flags->f_minus == 1)
		ft_display_int_inverse(flags, num);
	else
	{
		if (num[0] == '-' && flags->f_zero == 1)
			flags->printed += write(1, "-", 1);
		flags->printed += ft_display_width(flags, num);
		flags->printed += ft_display_precision(flags, num);
		if (num[0] == '-' && (flags->f_zero == 1 || flags->n_precision > 0))
		{
			num++;
			flags->printed += write(1, num, ft_strlen(num));
			free(--num);
		}
		else
		{
			flags->printed += write(1, num, ft_strlen(num));
			free(num);
		}
	}
	return (flags->printed);
}
