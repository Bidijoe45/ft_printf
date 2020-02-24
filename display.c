/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:28:49 by apavel            #+#    #+#             */
/*   Updated: 2020/02/24 12:41:26 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display(t_flags *flags, char type)
{
	if (type == 'c')
		ft_display_c(flags);
	if (type == 's')
		printf("s type not implemented \n");
	if (type == 'p')
		printf("p type not implemented \n");
	if (type == 'd' || type == 'i')
		ft_display_int(flags);
	if (type == 'u')
		printf("u type not implemented \n");
	if (type == 'x')
		printf("x type not implemented \n");
	if (type == 'X')
		printf("X type not implemented \n");
	return (0);
}
