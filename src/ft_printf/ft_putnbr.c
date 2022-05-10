/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:12:50 by fael-bou          #+#    #+#             */
/*   Updated: 2021/12/21 03:30:11 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (write (1, "-2147483648", 11));
	else if (nb < 0)
	{
		nb = nb * (-1);
		count += write (1, "-", 1);
	}
	return (ft_put_unsigned_int(nb) + count);
}

int	ft_put_unsigned_int(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 0 && nb < 10)
	{
		ft_putchar (nb + '0');
		count++;
	}
	if (nb >= 10)
	{
		count += ft_put_unsigned_int(nb / 10);
		count += ft_put_unsigned_int(nb % 10);
	}
	return (count);
}

int	ft_put_hexa(unsigned long long nb, const char specifier)
{
	int	count;

	count = 0;
	if (nb < 16)
	{
		if (nb < 10)
			count += ft_putchar(nb + '0');
		else if (specifier == 'X')
				count += ft_putchar(nb + 55);
		else if (specifier == 'x')
				count += ft_putchar(nb + 87);
	}
	else
	{
		count += ft_put_hexa(nb / 16, specifier);
		count += ft_put_hexa(nb % 16, specifier);
	}
	return (count);
}

int	ft_put_ptr(unsigned long long nb)
{
	write(1, "0x", 2);
	return (ft_put_hexa(nb, 'x') + 2);
}
