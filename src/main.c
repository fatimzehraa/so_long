/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:05:58 by fael-bou          #+#    #+#             */
/*   Updated: 2022/05/10 19:41:12 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int	set_win(t_context *ctx, t_list *lines)
{
	t_list	*cur;
	t_map	*map;
	int		side;

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
	map->character = mlx_xpm_file_to_image(ctx->mlx, "images/P.xpm", &side, &side);
	map->way = mlx_xpm_file_to_image(ctx->mlx, "images/0.xpm", &side, &side);
	map->wall = mlx_xpm_file_to_image(ctx->mlx, "images/1.xpm", &side, &side);
	map->coin = mlx_xpm_file_to_image(ctx->mlx, "images/C.xpm", &side, &side);
	map->exit = mlx_xpm_file_to_image(ctx->mlx, "images/E.xpm", &side, &side);
	return (map->character && map->wall && map->coin && map->exit && map->way);
}

int	close_game(void *param)
{
	free_ctx((t_context *)param);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_context	ctx;
	t_list		*lines;

	if (args_err(argc, argv))
		return (1);
	init_ctx(&ctx);
	lines = parse(argv[1], &ctx.map);
	if (lines == NULL)
		return (1);
	ctx.map.lines = lines;
	if (!set_win(&ctx, lines))
		return (free_ctx(&ctx), 1);
	ctx.win = mlx_new_window(ctx.mlx, ctx.map.width, ctx.map.height, "so_long");
	mlx_key_hook(ctx.win, key_event, &ctx);
	mlx_hook(ctx.win, 17, 0, close_game, &ctx);
	draw(&ctx);
	mlx_loop(ctx.mlx);
	free_ctx(&ctx);
	return (0);
}
