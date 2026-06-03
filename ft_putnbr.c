/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:38:34 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/03 16:57:36 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	ft_putnbr(int n)
{
	int		count;
	long	number;

	count = 0;
	number = n;
	if (number < 0)
	{
		count = count + ft_putchar('-');
		number = -number;
	}
	if (number >= 10)
		count = count + ft_putnbr(number / 10);
	count = count + ft_putchar((char)(number % 10 + '0'));
	return (count);
}
/*
int	main(void)
{
	printf("%s\n", "Output:");
	ft_putnbr(-2147483648);
	printf("%c", '\n');
	printf("\n%d", ft_putnbr(-2147483648));
	printf("%c", '\n');
	printf("\n%s\n", "Real Output:");
	printf("%d", -2147483648);
	printf("%c", '\n');
	printf("\n%d", printf("%d", -2147483648));
//additional test:
	ft_putnbr(0);
	printf("\n%d\n", ft_putnbr(0));
	printf("%d", 0);
	printf("\n%d\n", printf("%d", 0));
}
*/