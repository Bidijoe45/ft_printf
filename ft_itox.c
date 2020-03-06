/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:54 by apavel            #+#    #+#             */
/*   Updated: 2020/03/04 18:34:13 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count_digits(unsigned int n)
{
	size_t	digits;
	unsigned int num;

	num = (n < 0) ? -n : n;
	digits = (n < 0) ? 2 : 1;
	if (n == 0)
		return 1;
	while (num /= 16)
		digits++;
	return (digits);
}

char			*ft_itox(unsigned int n, char type)
{
	char	*str;
	int		i;
	int		digits;
	char	*letters_down;
	char	*letters_up;

	letters_down = "0123456789abcdef";
	letters_up = "0123456789ABCDEF";
	digits = ft_count_digits(n);
	if (!(str = malloc(sizeof(char) * (digits + 1))))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[digits] = '\0';
		return (str);
	}
	i = digits;
	str[digits] = '\0';
	while (n > 0)
	{
		if (type == 'x')
			str[i - 1] = letters_down[(n % 16)];
		else if (type == 'X')
			str[i - 1] = letters_up[(n % 16)];
		n /= 16;
		i--;
	}
	return (str);
}
