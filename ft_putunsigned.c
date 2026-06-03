/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:08:04 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/03 17:28:36 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count = count + ft_putunsigned(n / 10);
	count = count + ft_putchar((char)(n % 10 + '0'));
	return (count);
}
/*
int	main(void)
{
	int	len1;
	int	len2;

	printf("Mine: ");
	len1 = ft_putunsigned(-5);

	printf("\nReal: ");
	len2 = printf("%u", -5);

	printf("\n\nMy return: %d", len1);
	printf("\nReal return: %d\n", len2);
}*/
