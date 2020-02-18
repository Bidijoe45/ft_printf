/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:49:25 by apavel            #+#    #+#             */
/*   Updated: 2020/02/17 18:35:15 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

Format	*start_format()
{
	Format *format;
	
	format = malloc(sizeof(Format));
	format->minus = -1;
	format->zero = -1;
	format->n = -1;
	format->star = -1;

	return (format);
}

int		ft_print_format(va_list args, char c)
{
	int ret;

	if (c == 'c')
		ret = character_handler(va_arg(args, int));
	else if (c == 's')
		ret = string_handler(va_arg(args, char *));
	else if (c == 'd')
		ret = sinteger_handler(va_arg(args, int));
	else if (c == 'i')
		ret = sinteger_handler(va_arg(args, int));
	else if (c == 'u')
		printf("|Not implemented u|");
	else if (c == 'p')
		printf("|Not implemented p|");
	else if (c == 'x')
		printf("|Not implemented x|");
	else if (c == 'X')	
		printf("|Not implemented X|");
	else if (c == '%')
		write(1, "%", 1);
	
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	Format *s_format;
	
	s_format = start_format();
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			char type = get_datatype(format[i]);
			write(1, &type, 1);
//			ft_print_format(args, get_datatype(format[i]));
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	free(format);	
	return (1);
}

