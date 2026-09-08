/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 13:06:58 by dboldino          #+#    #+#             */
/*   Updated: 2026/09/08 13:18:32 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_arg_check(const char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if ((type == 'i') || (type == 'd'))
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (type == 'x' || type == 'X')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), type));
	else if (type == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;
	int		check;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			check = ft_arg_check(*(++str), args);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			if (ft_putchar(*str) == -1)
				return (-1);
			len++;
		}
		str++;
	}
	va_end(args);
	return (len);
}
