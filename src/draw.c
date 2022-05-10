/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:27:10 by fael-bou          #+#    #+#             */
/*   Updated: 2022/05/10 19:37:50 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_context ctx, int x, int y, void *img)
{
	mlx_put_image_to_window(ctx.mlx, ctx.win, img, x, y);
}

void	mini_draw(t_context *ctx, int x, int y, char a)
{
	if (a == '1')
		put_img(*ctx, x, y, ctx->map.wall);
	else if (a == '0')
		put_img(*ctx, x, y, ctx->map.way);
	else if (a == 'C')
		put_img(*ctx, x, y, ctx->map.coin);
	else if (a == 'P')
		put_img(*ctx, x, y, ctx->map.character);
	else if (a == 'E')
		put_img(*ctx, x, y, ctx->map.exit);
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
