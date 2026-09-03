/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:47:00 by sofernan          #+#    #+#             */
/*   Updated: 2024/08/05 18:18:14 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int number, char *hex_digits)
{
	int	remainder[16];
	int	i;
	int	printed_chars;

	i = 0;
	printed_chars = 0;
	if (number == 0)
		printed_chars += ft_putchar('0');
	while (number != 0)
	{
		remainder[i] = number % 16;
		number = number / 16;
		i++;
	}
	while (--i >= 0)
	{
		printed_chars += ft_putchar(hex_digits[remainder[i]]);
	}
	return (printed_chars);
}
/*
int main(void)
{
	unsigned int	number = 42;
	char			*hex_digits = "0123456789ABCDEF";

	ft_print_hex(number, hex_digits);
	ft_putchar('\n');
	return (0);
}*/