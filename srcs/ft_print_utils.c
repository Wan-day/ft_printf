/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 13:09:26 by dboldino          #+#    #+#             */
/*   Updated: 2026/09/08 13:18:25 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(long nb)
{
	long		num;
	int			len;
	int			temp_len;

	len = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len += 1;
		nb *= -1;
	}
	num = nb % 10 + '0';
	if (nb > 9)
	{
		temp_len = ft_putnbr(nb / 10);
		if (temp_len == -1)
			return (-1);
		len += temp_len;
	}
	if (ft_putchar(*num) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putnbr_hexa(unsigned long nbr, char up)
{
	int		len;
	int		mod;
	char	*base;
	int		temp_len;

	mod = 0;
	len = 0;
	if (up == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr > 15)
	{
		temp_len = ft_putnbr_hexa((nbr / 16), up);
		if (temp_len == -1)
			return (-1);
		len += temp_len;
	}
	mod = nbr % 16;
	if (ft_putchar(base[mod]) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	temp_len;

	len = 0;
	temp_len = 0;
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	temp_len = ft_putnbr_hexa((unsigned long)ptr, 'x');
	if (temp_len == -1)
		return (-1);
	len += temp_len;
	return (len);
}

int	ft_putstr(char *str1)
{
	int	len;

	if (!str1)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*str1 != '\0')
	{
		if (ft_putchar(*str1) == -1)
			return (-1);
		len++;
		str1++;
	}
	return (len);
}
