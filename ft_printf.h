/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:47:34 by sofernan          #+#    #+#             */
/*   Updated: 2024/08/05 18:34:41 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *str);
int		ft_print_ptr(size_t ptr);
void	ft_putchar_fd(char c, int fd);
int		ft_putnbr(int number);
int		ft_print_unsigned(unsigned int number);
int		ft_print_hex(unsigned int number, char *hex_digits);

#endif
