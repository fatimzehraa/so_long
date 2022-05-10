/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:52:21 by fael-bou          #+#    #+#             */
/*   Updated: 2021/12/21 03:30:12 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(va_list ptr, const char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ptr, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ptr, char *));
	else if (specifier == 'p')
		count += ft_put_ptr(va_arg(ptr, unsigned long long));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ptr, int));
	else if (specifier == 'u')
		count += ft_put_unsigned_int(va_arg(ptr, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_put_hexa(va_arg(ptr, unsigned int), specifier);
	else
		count += ft_putchar(specifier);
	return (count);
}
