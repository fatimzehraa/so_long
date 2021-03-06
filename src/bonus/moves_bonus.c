/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 04:24:13 by fael-bou          #+#    #+#             */
/*   Updated: 2022/05/10 20:08:19 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	go_right(t_map *map)
{
	char	*line;
	t_list	*cur;
	int		i;

	cur = map->lines;
	while (cur)
	{
		line = cur->content;
		i = ft_stri(line, 'P');
		if (i != -1)
		{
			map->collectibles -= (line[i + 1] == 'C');
			if (line[i + 1] == 'E')
				return (map->collectibles);
			if (line[i + 1] == '1' || line[i + 1] == 'W')
				return (line[i + 1] == '1');
			line[i] = '0';
			line[i + 1] = 'P';
			++(map->count);
			break ;
		}
		cur = cur->next;
	}
	return (1);
}

int	go_left(t_map *map)
{
	char	*line;
	t_list	*cur;
	int		i;

	cur = map->lines;
	while (cur)
	{
		line = cur->content;
		i = ft_stri(line, 'P');
		if (i != -1)
		{
			map->collectibles -= (line[i - 1] == 'C');
			if (line[i - 1] == 'E')
				return (map->collectibles);
			if (line[i - 1] == '1' || line[i - 1] == 'W')
				return (line[i - 1] == '1');
			line[i] = '0';
			line[i - 1] = 'P';
			++(map->count);
			break ;
		}
		cur = cur->next;
	}
	return (1);
}

int	go_up(t_map *map)
{
	t_list	*cur;
	char	*line;
	char	*prev_line;
	int		i;

	cur = map->lines;
	while (cur)
	{
		line = cur->content;
		i = ft_stri(line, 'P');
		if (i != -1)
		{
			map->collectibles -= (prev_line[i] == 'C');
			if (prev_line[i] == 'E')
				return (map->collectibles);
			if (prev_line[i] == '1' || prev_line[i] == 'W')
				return (prev_line[i] == '1');
			line[i] = '0';
			prev_line[i] = 'P';
			++(map->count);
		}
		prev_line = cur->content;
		cur = cur->next;
	}
	return (1);
}

int	go_down(t_map *map)
{
	t_list	*cur;
	char	*line;
	int		i;

	cur = map->lines;
	while (cur)
	{
		line = cur->content;
		i = ft_stri(line, 'P');
		if (i != -1)
		{
			map->collectibles -= (cur->next->content[i] == 'C');
			if (cur->next->content[i] == 'E')
				return (map->collectibles);
			if (cur->next->content[i] == '1' || cur->next->content[i] == 'W' )
				return (cur->next->content[i] == '1');
			line[i] = '0';
			cur->next->content[i] = 'P';
			++(map->count);
			return (1);
		}
		cur = cur->next;
	}
	return (1);
}

int	key_event(int key, t_context *ctx)
{
	int	stay_or_not;

	stay_or_not = 1;
	if (key == UP_KEY)
		stay_or_not = go_up(&ctx->map);
	else if (key == DOWN_KEY)
		stay_or_not = go_down(&ctx->map);
	else if (key == LEFT_KEY)
		stay_or_not = go_left(&ctx->map);
	else if (key == RIGHT_KEY)
		stay_or_not = go_right(&ctx->map);
	else if (key == ESC_KEY)
		close_game(ctx);
	else
		return (0);
	mlx_clear_window(ctx->mlx, ctx->win);
	draw(ctx);
	if (stay_or_not == 0)
		close_game(ctx);
	print_moves(ctx);
	return (1);
}
