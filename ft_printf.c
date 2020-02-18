/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:49:25 by apavel            #+#    #+#             */
/*   Updated: 2020/02/18 18:53:45 by apavel           ###   ########.fr       */
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

int		ft_print_format(va_list args, Format *s_format, char type)
{
	int ret;

	if (type == 'c')
		ret = character_handler(va_arg(args, int));
	else if (type == 's')
		ret = string_handler(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		ret = sinteger_handler(va_arg(args, int));
	else if (type == 'u')
		printf("|Not implemented u|");
	else if (type == 'p')
		printf("|Not implemented p|");
	else if (type == 'x')
		printf("|Not implemented x|");
	else if (type == 'X')	
		printf("|Not implemented X|");
	else if (type == '%')
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
	
	printf("num: %d\n", get_width("53002", s_format));

	/*
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			parse_flags(&format[i], s_format);
			ft_print_format(args, s_format, get_datatype(&format[i]));
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	*/
	free(s_format);	
	return (1);
}

