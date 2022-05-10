/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:27:34 by fael-bou          #+#    #+#             */
/*   Updated: 2022/05/10 19:55:40 by fael-bou         ###   ########.fr       */
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

	i = count_size(n);
	ascii_s[i] = 0;
	while (i > 0)
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
