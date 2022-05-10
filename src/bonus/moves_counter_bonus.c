/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:27:34 by fael-bou          #+#    #+#             */
/*   Updated: 2022/05/10 17:19:44 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long_bonus.h"

static int	count_size(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void	ft_itoa(char *ascii_s, unsigned int n)
{
	int		i;
	int		is_neg;

	is_neg = n < 0;
	i = count_size(n);
	ascii_s[0] = '-';
	ascii_s[i] = 0;
	if (is_neg)
		n = -n;
	while (i > is_neg)
	{
		i--;
		ascii_s[i] = n % 10 + '0';
		n = n / 10;
	}
}

void	print_moves(t_context *ctx)
{
	char	str[100];

	ft_itoa(str, ctx->map.count);
	mlx_string_put(ctx->mlx, ctx->win, 0, ctx->map.height + 10, 0xFFFFFF, str);
}
