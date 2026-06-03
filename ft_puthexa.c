/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:27:42 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/03 18:46:31 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	ft_puthexa(unsigned long n, int uppercase)
{
	char	*base_lower;
	char	*base_upper;
	char	*base;
	int		count;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (uppercase)
		base = base_upper;
	else
		base = base_lower;
	count = 0;
	if (n >= 16)
		count = count + ft_puthexa(n / 16, uppercase);
	count = count + ft_putchar(base[n % 16]);
	return (count);
}
/*
int	main(void)
{
	printf("MY OUTPUT:\n");
	printf("0        : ");
	printf("%d\n", ft_puthexa(0, 0));
	printf("15 lower : ");
	printf("%d\n", ft_puthexa(15, 0));
	printf("15 upper : ");
	printf("%d\n", ft_puthexa(15, 1));
	printf("255 lower: ");
	printf("%d\n", ft_puthexa(255, 0));
	printf("255 upper: ");
	printf("%d\n", ft_puthexa(255, 1));
	printf("UINT_MAX : ");
	printf("%d\n", ft_puthexa(4294967295u, 0));
	printf("\nREAL OUTPUT:\n");
	printf("0        : ");
	printf("%x", 0);
	printf("\n%d\n", printf("%x", 0));
	printf("15 lower : ");
	printf("%x", 15);
	printf("\n%d\n", printf("%x", 15));
	printf("15 upper : ");
	printf("%X", 15);
	printf("\n%d\n", printf("%X", 15));
	printf("255 lower: ");
	printf("%x", 255);
	printf("\n%d\n", printf("%x", 255));
	printf("255 upper: ");
	printf("%X", 255);
	printf("\n%d\n", printf("%X", 255));
	printf("UINT_MAX : ");
	printf("%x", 4294967295u);
	printf("\n%d\n", printf("%x", 4294967295u));
	return (0);
}
*/
/*Notes:
Decimal:      0 1 2 3 4 5 6 7 8 9
Hexadecimal:  0 1 2 3 4 5 6 7 8 9 A B C D E F
When you convert 255 to hexadecimal, you repeatedly divide by 16
255 / 16 = 15 remainder 15 (f)
15 / 16 = 0 remainder 15 (f)
So 255 in hexadecimal is "ff" (lowercase) or "FF" (uppercase).
What does if (uppercase) mean?
It checks if the uppercase flag is set (non-zero)
If it is, it uses the uppercase hexadecimal digits (A-F) from base_upper
If not, it uses the lowercase hexadecimal digits (a-f) from base_lower
This allows the function to print either uppercase or lowercase hexadecimal
based on the value of the uppercase parameter:
0      = false
non-zero = true
Test cases:
0 → verifies that zero prints as "0" and not as an empty string.
15 → verifies the first hexadecimal letter (f / F).
255 → verifies recursion (ff / FF).
4294967295u → verifies the largest unsigned int (ffffffff)
which is important for %x and %X.
The printed lengths → verify the return values
Expected hexadecimal outputs:
0
f
F
ff
FF
ffffffff*/