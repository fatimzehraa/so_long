/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 04:24:13 by fael-bou          #+#    #+#             */
/*   Updated: 2022/05/10 17:28:55 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

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
			if (line[i + 1] == '1')
				return (1);
			line[i] = '0';
			line[i + 1] = 'P';
			ft_printf("%d\n", ++(map->count));
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
			if (line[i - 1] == '1')
				return (1);
			line[i] = '0';
			line[i - 1] = 'P';
			ft_printf("%d\n", ++(map->count));
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
			if (prev_line[i] == '1')
				return (1);
			line[i] = '0';
			prev_line[i] = 'P';
			ft_printf("%d\n", ++(map->count));
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
			if (cur->next->content[i] == '1')
				return (1);
			line[i] = '0';
			cur->next->content[i] = 'P';
			ft_printf("%d\n", ++(map->count));
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
		exit (0);
	else
		return (0);
	draw(ctx);
	if (stay_or_not == 0)
	{
		free_ctx(ctx);
		exit (0);
	}
	return (1);
}
