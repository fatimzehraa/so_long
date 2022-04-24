/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:05:58 by fael-bou          #+#    #+#             */
/*   Updated: 2022/04/24 04:19:58 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "get_next_line.h"
#include "list.h"
#include "so_long.h"

void set_win(t_map *map, t_list *lines)
{
	t_list *cur;

	map->height = 0;
	cur = lines;
	while (cur)
	{
		(map->height)++; 
		cur = cur->next;
	}
	map->height *= SIDE_SQUARE;
	map->width = ft_strlen(lines->content) * SIDE_SQUARE;
	
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

void draw(t_context ctx)
{
	int y = 0;
	char *line;
	t_list *cur;

	cur = ctx.map.lines;
	while (y < ctx.map.height)
	{
		int x = 0;
		line = cur->content;
		while (x < ctx.map.width)
		{
			if (*line == '1')
				put_img(ctx, x, y, "1.xpm");
			else if (*line == '0')
				set_square(ctx, x, y, 0x000000);
//				put_img(ctx, x, y, "P.xpm");
			else if (*line == 'C')
				put_img(ctx, x, y, "coin.xpm");
//			else if (*line == 'P')
//				set_square(ctx, x, y, 0xF000FF);
			else if (*line == 'P')
				put_img(ctx, x, y, "P.xpm");
			else if (*line == 'E')
				put_img(ctx, x, y, "Eclosed.xpm");
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

	lines = parse("maps");
	if (lines)
		printf("%s", (char *)lines->content);

	ctx.map.lines = lines;
	set_win(&ctx.map, lines);
	ctx.mlx = mlx_init();
	ctx.win = mlx_new_window(ctx.mlx, ctx.map.width, ctx.map.height, "so_long");


//	set_square(ctx, 20, 20, 0xFFFFFF);
	draw(ctx);
	mlx_loop(ctx.mlx);
}
