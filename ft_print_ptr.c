/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:47:10 by sofernan          #+#    #+#             */
/*   Updated: 2024/08/05 18:24:05 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_ptr_len(size_t number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
		len++;
		number = number / 16;
	}
	return (len);
}

void	ft_put_ptr_hex(size_t number)
{
	if (number >= 16)
	{
		ft_put_ptr_hex(number / 16);
		ft_put_ptr_hex(number % 16);
	}
	else
	{
		if (number <= 9)
			ft_putchar_fd((number + '0'), 1);
		else
			ft_putchar_fd((number - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(size_t ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		len += write(1, "(nil)", 5);
	}
	else
	{
		len += write(1, "0x", 2);
		ft_put_ptr_hex(ptr);
		len += ft_ptr_len(ptr);
	}
	return (len);
}

/*int main(void)
{
	size_t ptr1 = 0;
	size_t ptr2 = 255;

	ft_print_ptr(ptr1);
	ft_putchar_fd('\n', 1);

	ft_print_ptr(ptr2);
	ft_putchar_fd('\n', 1);

	ft_print_ptr(0);

	return (0);
}*/
