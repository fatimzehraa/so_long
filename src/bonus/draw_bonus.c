/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:27:10 by fael-bou          #+#    #+#             */
/*   Updated: 2022/05/09 23:26:46 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img(t_context ctx, int x, int y, void *img)
{
	mlx_put_image_to_window(ctx.mlx, ctx.win, img, x, y);
}

void	set_square(t_context ctx, int x, int y, int color)
{
	int	original_x;
	int	i;
	int	k;

	original_x = x;
	i = y + SIDE_SQUARE;
	k = x + SIDE_SQUARE;
	while (y <= i)
	{
		x = original_x;
		while (x <= k)
		{
			mlx_pixel_put(ctx.mlx, ctx.win, x, y, color);
			x++;
		}
		y++;
	}
}

void	mini_draw(t_context *ctx, int x, int y, char a)
{
	if (a == '1')
		put_img(*ctx, x, y, ctx->map.wall);
	else if (a == '0')
		set_square(*ctx, x, y, 0xFFFFFF);
	else if (a == 'C')
		put_img(*ctx, x, y, ctx->map.coin);
	else if (a == 'P')
		put_img(*ctx, x, y, ctx->map.character);
	else if (a == 'E')
		put_img(*ctx, x, y, ctx->map.exit);
	else if (a == 'W')
		put_img(*ctx, x, y, ctx->map.enemy);
}

void	draw(t_context *ctx)
{
	int		y;
	int		x;
	char	*line;
	t_list	*cur;

	y = 0;
	cur = ctx->map.lines;
	while (y < ctx->map.height)
	{
		x = 0;
		line = cur->content;
		while (x < ctx->map.width)
		{
			mini_draw(ctx, x, y, *line);
			line++;
			x += SIDE_SQUARE;
		}
		cur = cur->next;
		y += SIDE_SQUARE;
	}
}
