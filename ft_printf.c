/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:47:26 by sofernan          #+#    #+#             */
/*   Updated: 2024/08/05 18:32:04 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	converter(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, uintptr_t)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_putchar('%'));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += converter(format[i + 1], args);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/*int main(void)
{
    ft_printf("Char: %c\n", 'S');
    ft_printf("String: %s\n", "Hello, 42!");
    ft_printf("Pointer: %p\n", NULL);
    ft_printf("Pointer: %p\n", (void *)0x12345678);
    ft_printf("Decimal: %d\n", 12345);
    ft_printf("Integer: %i\n", -12345);
    ft_printf("Unsigned: %u\n", 12345);
    ft_printf("Hex (lower): %x\n", 42);
    ft_printf("Hex (upper): %X\n", 42);
    ft_printf("Percent: %%\n");

    return (0);
}*/
