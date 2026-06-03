/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:45:27 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/03 18:28:51 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	ft_activate_specifier(char specifier, va_list arg_pointer)
{
	if (specifier == 'c')
		return (ft_putchar((char)va_arg(arg_pointer, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(arg_pointer, char *)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(arg_pointer, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(arg_pointer, int)));
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(arg_pointer, unsigned int)));
	else if (specifier == 'x')
		return (ft_puthexa(va_arg(arg_pointer, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_puthexa(va_arg(arg_pointer, unsigned int), 1));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}
/*return (ft_putstr(va_arg(arg_pointer, char *)));
is quivalent to:
char *str;
str = va_arg(arg_pointer, char *);
return (ft_putstr(str));
Another example:
else if (specifier == 'p')
{
	void *ptr;

	ptr = va_arg(arg_pointer, void *);
	return (ft_putptr(ptr));
}
I could even add the octal specifier:
else if (specifier == 'o')
		return (ft_putoctal(va_arg(arg_pointer, unsigned int)));
And add the function ft_putoctal in ft_printf.h:
int	ft_putoctal(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 8)
		count = count + ft_putoctal(n / 8);
	count = count + ft_putchar("01234567"[n % 8]);
	return (count);
}	
*/

int	ft_printf(const char *format_str, ...)
{
	va_list	arg_pointer;
	int		count;
	int		i;

	if (format_str == NULL)
		return (-1);
	va_start(arg_pointer, format_str);
	i = 0;
	count = 0;
	while (format_str[i])
	{
		if (format_str[i] == '%' && format_str[i + 1])
		{
			i++;
			count = count + ft_activate_specifier(format_str[i], arg_pointer);
		}
		else if (format_str[i] != '%')
			count = count + ft_putchar(format_str[i]);
		i++;
	}
	va_end(arg_pointer);
	return (count);
}
/*if (format_str[i] == '%' && format_str[i + 1] != '\0')
is redundant
better if (format_str[i] == '%' && format_str[i + 1])
because format_str[i + 1] == '\0' already means 0
which is false in C 
0 is false and non-zero is true, basically*/
/*
int	main(void)
{
	int		num;
	char	*str;
	void	*ptr;
	char	*s;

	num = 42;
	str = "Erfolg!";
	ptr = &num;
	s = NULL;
	printf("MY FUNC:\n");
	ft_printf("char:          %c\n", 'A');
	ft_printf("string:        %s\n", str);
	ft_printf("null string:   %s\n", s);
	ft_printf("pointer:       %p\n", ptr);
	ft_printf("null pointer:  %p\n", NULL);
	ft_printf("decimal:       %d\n", num);
	ft_printf("negative:      %d\n", -42);
	ft_printf("integer:       %i\n", num);
	ft_printf("INT_MIN: %d\n", -2147483648);
	ft_printf("INT_MAX: %d\n", 2147483647);
	ft_printf("max unsigned:      %u\n", 4294967295u);
	ft_printf("min unsigned:      %u\n", 0u);
	ft_printf("unsigned -1:   %u\n", -1);
	ft_printf("hex lower:     %x\n", 15);
	ft_printf("max hex:     %X\n", 4294967295u);
	ft_printf("percent:       100%%\n");
	ft_printf("\n%s scored %x in printf\n", "Diana", 256);
	ft_printf("\nLength of Erfolg!:  %d\n", ft_printf("\nErfolg!"));
	ft_printf("%s %d %x %c\n", "omatalla", 42, 42, 'Z');
	ft_printf("%%%%%%\n");
	ft_printf("unsigned -1:   %u\n", -1);
	ft_printf("signed -1:   %d\n", -1);
	//real printf for comparison:
	printf("\nPrintf Real Output:\n");
	printf("char:          %c\n", 'A');
	printf("string:        %s\n", str);
	printf("null string:   %s\n", s);
	printf("pointer:       %p\n", ptr);
	printf("null pointer:  %p\n", NULL);
	printf("decimal:       %d\n", num);
	printf("negative:      %d\n", -42);
	printf("integer:       %i\n", num);
	printf("INT_MIN: %d\n", -2147483648);
	printf("INT_MAX: %d\n", 2147483647);
	printf("max unsigned:      %u\n", 4294967295u);
	printf("min unsigned:      %u\n", 0u);
	printf("unsigned -1:   %u\n", -1);
	printf("hex lower:     %x\n", 15);
	printf("max hex:     %X\n", 4294967295u);
	printf("percent:       100%%\n");
	printf("\n%s scored %x in libft\n", "Diana", 256);
	printf("\nLength of Erfolg!:  %d\n", printf("\nErfolg!"));
	printf("%s %d %x %c\n", "omatalla", 42, 42, 'Z');
	printf("%%%%%%\n");
	printf("unsigned -1:   %u\n", -1);
	printf("signed -1:   %d\n", -1);
}*/
/*an unsigned int is usually 32 bits
A 32-bit unsigned integer can store: 0 to 4,294,967,295 (2^32 - 1)
The u means: Treat this literal as unsigned
Without the u: the compiler must decide whether it is an:
int or a long int or a long long int
depending on the platform
Adding u removes ambiguity*/
