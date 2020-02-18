/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:12:37 by apavel            #+#    #+#             */
/*   Updated: 2020/02/17 17:00:14 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include<stdio.h>

int main()
{
	
	//ft_printf("char: %c, int: %d, int: %i\n", 'Q', 6, 966666669);
	//printf("%07d\n", 5);
	printf("1  |%10d|\n", 1977);	
	printf("2  |%10d|\n", 11977);	
	printf("3  |%5d|\n", 123456789);
	printf("4  |%-10d|\n", 11977);
	printf("5  |%010d|\n", 1977);
	printf("6  |%*d|\n", 10, 1977);	
	printf("7  |%*d|\n", 10, 1977);	
	printf("8  |%0*d|\n", 10, 1977);	
	printf("9  |%0*d|\n", 10, 1977);	
	printf("10 |%0*.6d|\n", 10, 1977);
	printf("11 |%0*.2d|\n", 10, 1977);
	printf("12 |%0*.*d|\n", 3, 10, 1977);
	printf("13 |%0*.*d|\n", 20, 5, 1977);

	return (1);
}
