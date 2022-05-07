/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:14:19 by fael-bou          #+#    #+#             */
/*   Updated: 2022/05/07 15:05:32 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_stri(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	end_with(char *s1, char *s2)
{
	int	i;
	int	k;

	i = ft_strlen(s1);
	k = ft_strlen(s2);
	if (k > i)
		return (0);
	while (k--)
	{
		i--;
		if (s1[i] != s2[k])
			return (0);
	}
	return (1);
}

void	init_ctx(t_context *ctx)
{
	if (ctx != NULL)
	{
		ctx->mlx = mlx_init();
		ctx->win = NULL;
		ctx->map.lines = NULL;
		ctx->map.wall = NULL;
		ctx->map.coin = NULL;
		ctx->map.character = NULL;
		ctx->map.exit = NULL;
		ctx->map.count = 0;
	}
}

void	free_ctx(t_context *ctx)
{
	if (ctx != NULL)
	{
		if (ctx->map.lines != NULL)
			ft_lstclear(&ctx->map.lines, free);
		if (ctx->map.wall != NULL)
			mlx_destroy_image(ctx->mlx, ctx->map.wall);
		if (ctx->map.character != NULL)
			mlx_destroy_image(ctx->mlx, ctx->map.character);
		if (ctx->map.coin != NULL)
			mlx_destroy_image(ctx->mlx, ctx->map.coin);
		if (ctx->map.exit != NULL)
			mlx_destroy_image(ctx->mlx, ctx->map.exit);
		if (ctx->win != NULL)
			mlx_destroy_window(ctx->mlx, ctx->win);
	}
}
