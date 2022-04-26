/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 04:24:13 by fael-bou          #+#    #+#             */
/*   Updated: 2022/04/26 06:48:03 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "list.h"
#include "so_long.h"

int ft_stri(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int go_right(t_map *map)
{
	char *line;
	t_list *cur;
	int i;

	cur = map->lines;
	while(cur)
	{
		line = cur->content;
		i = ft_stri(line, 'P');
		if (i != -1)
		{
			if (line[i +1] == '1')
				return (1);
			line[i] = '0';
			line[i + 1] = 'P';
			break;
		}
		cur = cur->next;
	}
	printf("go_right\n");
	return (1);
}

int go_left(t_map *map)
{
	char *line;
	t_list *cur;
	int i;

	cur = map->lines;
	while(cur)
	{
		line = cur->content;
		i = ft_stri(line, 'P');
		if (i != -1)
		{
			if (line[i - 1] == '1')
				return (1);
			line[i] = '0';
			line[i - 1] = 'P';
			break;
		}
		cur = cur->next;
	}
	printf("go_left\n");
	return (1);
}

int go_up(t_map *map)
{
	t_list *cur;
	char *line;
	char *prev_line;
	int i;

	cur = map->lines;
	while (cur)
	{
		line = cur->content;
		i = ft_stri(line, 'P');
		if (i != -1)
		{
			if (prev_line[i] == '1')
				return (1);
			line[i] = '0';
			prev_line[i] = 'P';
		}
		prev_line = cur->content;
		cur = cur->next;
	}
	printf("go_up\n");
	return (1);
}

int go_down(t_map *map)
{
	t_list *cur;
	char *line;
	int i;

	cur = map->lines;
	while (cur)
	{
		line = cur->content;
		i = ft_stri(line, 'P');
		if (i != -1)
		{
			if (cur->next->content[i] == '1')
				return (1);
			line[i] = '0';
			cur->next->content[i] = 'P';
			return (1);
		}
		cur = cur->next;
	}
	printf("go_down\n");
	return (1);
}

/*
 *key_event kat9ra l key w kat3yet 3la l function li ghatdir dak lmove li 
 kaychbh l event
 * */

int key_event(int key, t_context *ctx)
{
	int stay_or_not;

	stay_or_not = 1;
	if (key == UP_KEY)
		stay_or_not = go_up(&ctx->map);
	if (key == DOWN_KEY)
		stay_or_not = go_down(&ctx->map);
	if (key == LEFT_KEY)
		stay_or_not = go_left(&ctx->map);
	if (key == RIGHT_KEY)
		stay_or_not = go_right(&ctx->map);

	mlx_clear_window( ctx->mlx, ctx->win);
	draw (ctx);
//	fflush(stdout);
	if (stay_or_not == 0)
		exit(0);
	return (1);
}
