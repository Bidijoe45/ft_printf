/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:03:58 by apavel            #+#    #+#             */
/*   Updated: 2020/02/18 18:53:44 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *g_types = "cspdiuxX";

char	get_datatype(const char *format)
{
	int i;
	i = 0;
	while (!ft_strchr(g_types, format[i]))
	{
		if (format[i] == '%')
			return (0);
		i++;
	}
	return (format[i]);
}

int		parse_flags(const char *format, Format *s_format)
{
	int i;
	
	get_flags(format, s_format);
	get_width(format, s_format);
	get_precision(format, s_format);

	return (0);
}
