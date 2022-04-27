/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:05:58 by fael-bou          #+#    #+#             */
/*   Updated: 2022/04/27 05:21:26 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "get_next_line.h"
#include "list.h"
#include "so_long.h"

void set_win(t_context *ctx, t_list *lines)
{
	t_list *cur;
	t_map *map;
	int side;

	map = &ctx->map;
	map->height = 0;
	cur = lines;
	while (cur)
	{
		(map->height)++; 
		cur = cur->next;
	}
	map->height *= SIDE_SQUARE;
	map->width = ft_strlen(lines->content) * SIDE_SQUARE;
	map->character = mlx_xpm_file_to_image(ctx->mlx, "P.xpm", &side, &side);
	map->wall = mlx_xpm_file_to_image(ctx->mlx, "1.xpm", &side, &side);
	map->coin = mlx_xpm_file_to_image(ctx->mlx, "C.xpm", &side, &side);
	map->exit = mlx_xpm_file_to_image(ctx->mlx, "E.xpm", &side, &side);
}

void set_square(t_context ctx , int x, int y, int color)
{
	int original_x = x;
	int i = y + SIDE_SQUARE;
	int k = x + SIDE_SQUARE;

	while (y < i)
	{
		x = original_x;
		while (x < k)
		{
	  		mlx_pixel_put(ctx.mlx, ctx.win, x, y, color);
  			x++;
		}
  		y++;
	}
}

void draw(t_context *ctx)
{
	int y = 0;
	char *line;
	t_list *cur;

	cur = ctx->map.lines;
	while (y < ctx->map.height)
	{
		int x = 0;
		line = cur->content;
		while (x < ctx->map.width)
		{
			if (*line == '1')
				put_img(*ctx, x, y, ctx->map.wall);
			else if (*line == '0')
				set_square(*ctx, x, y, 0xFFFFFF);
			else if (*line == 'C')
				put_img(*ctx, x, y, ctx->map.coin);
			else if (*line == 'P')
				put_img(*ctx, x, y, ctx->map.character);
			else if (*line == 'E')
				put_img(*ctx, x, y, ctx->map.exit);
			line++;
			x+= SIDE_SQUARE;
		}
		cur = cur->next;
		y += SIDE_SQUARE;
	}
}

int main()
{
	t_context ctx;
	t_list *lines;

	lines = parse("maps", &ctx.map);
	if (lines)
		printf("%s", (char *)lines->content);

	ctx.map.lines = lines;
	ctx.mlx = mlx_init();
	set_win(&ctx, lines);
	ctx.win = mlx_new_window(ctx.mlx, ctx.map.width, ctx.map.height, "so_long");
	mlx_key_hook( ctx.win, key_event, &ctx);

	draw(&ctx);
	mlx_loop(ctx.mlx);
}
