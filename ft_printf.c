/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:45:27 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/02 16:53:24 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_handle_conversion(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_handle_conversion(format[i], args);
		}
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int		num;
	char	*str;
	void	*ptr;
	char	*s;

	num = 42;
	str = "hello";
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
	ft_printf("unsigned:      %u\n", 4294967295u);
	ft_printf("unsigned -1:   %u\n", -1);
	ft_printf("hex lower:     %x\n", 15);
	ft_printf("hex upper:     %X\n", 15);
	ft_printf("percent:       100%%\n");
	ft_printf("\n%s scored %x in libft\n", "oscar", 256);
	ft_printf("\nlen of hello:  %d\n", ft_printf("\nhello"));

	printf("\nREAL FUNC:\n");

	printf("char:          %c\n", 'A');
	printf("string:        %s\n", str);
	printf("null string:   %s\n", s);
	printf("pointer:       %p\n", ptr);
	printf("null pointer:  %p\n", NULL);
	printf("decimal:       %d\n", num);
	printf("negative:      %d\n", -42);
	printf("integer:       %i\n", num);
	printf("unsigned:      %u\n", 4294967295u);
	printf("unsigned -1:   %u\n", -1);
	printf("hex lower:     %x\n", 15);
	printf("hex upper:     %X\n", 15);
	printf("percent:       100%%\n");
	printf("\n%s scored %x in libft\n", "oscar", 256);
	printf("\nlen of hello:  %d\n", ft_printf("\nhello"));
}
