/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:11:26 by apavel            #+#    #+#             */
/*   Updated: 2020/02/21 15:20:04 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_flags = "cspdiuxX";

void	ft_parse_flags(t_flags *flags, const char *format)
{
	int i;
	
	i = 0;
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
			flags->f_minus = 1;
		if (format[i] == '0' && flags->f_minus == 0)
			flags->f_zero = 1;
		i++;
	}
}

void	ft_parse_width(t_flags *flags, const char *format)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (format[i] == '-' || format[i] == '0')
		i++;
	while (!ft_strchr(g_flags, format[i]) && format[i] != '.')
	{
		if (format[i] == '*')
		{
			flags->f_star_width = 1;
			return ;
		}
		else if (format[i] >= '1' && format[i] <= '9')
		{
			flags->f_width = 1;
			num = num * 10 + format[i] - '0';
		}
		i++;
	}

	flags->n_width = num;
}

void	ft_parse_precision(t_flags *flags, const char *format)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (format[i] == '-' || format[i] == '0')
		i++;
	while (!ft_strchr(g_flags, format[i]) && format[i] != '.')
		i++;
	if (format[i] == '.')
	{
		flags->f_precision = 1;
		i++;
		if (format[i] == '*')
		{
			flags->f_star_precision = 1;
			return ;
		}
		while (format[i] >= '1' && format[i] <= '9')
		{
			num = num * 10 + format[i] - '0';
			i++;
		}
		flags->n_precision = num;
	}
}

char	ft_detect_type_and_display(t_flags *flags, const char *format)
{
	int i;

	i = 0;
	while (!ft_strchr(g_flags, format[i]))
		i++;
	ft_display(flags, format[i]);

	return (i);
}

int		ft_parse(t_flags *flags, const char *format)
{
	int i;
	
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			//ft_parse_flags(flags, &format[i]);
			//ft_parse_width(flags, &format[i]);
			//ft_parse_precision(flags, &format[i]);
			i = i + ft_detect_type_and_display(flags, &format[i]) + 1;
			//debug_print_s_flag(flags);
		}
		write(1, &format[i], 1);
		i++;
	}

	return (1);
}
