/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:54:59 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/03 16:28:22 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	ft_putptr(void *ptr)
{
	int				char_count;
	unsigned long	vp_address;

	if (!ptr)
		return (ft_putstr("(nil)"));
	char_count = 0;
	vp_address = (unsigned long)ptr;
	char_count = char_count + ft_putstr("0x");
	char_count = char_count + ft_puthexa(vp_address, 0);
	return (char_count);
}
/*
int	main(void)
{
	int	num = 42;
	int	*ptr = &num;

	printf("%s\n", "My output:");
	ft_putptr(ptr);
	printf("%c", '\n');
	ft_putptr(&num);
	printf("%d\n", ft_putptr(NULL));
	printf("%c", '\n');
	printf("\n%d", ft_putptr(ptr));
	printf("\n\n%s\n", "Real output:");
	printf("%p\n", (void *)&num);
	printf("%p\n", (void *)ptr);
	printf("\n%d\n", printf("%p", (void *)ptr));
	printf("%d\n", printf("%p", NULL));
}
*/
/*Pointers should not be stored in int or unsigned int
because on 64-bit systems they are 64 bits wide
That is why: vp_address = (unsigned long)ptr; */