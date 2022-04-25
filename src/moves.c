/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 04:24:13 by fael-bou          #+#    #+#             */
/*   Updated: 2022/04/25 06:41:34 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <stdio.h>
#include "get_next_line.h"
#include "list.h"
#include "so_long.h"

int go_up(t_map *map)
{
	(void) *map;
	printf("go up\n");
	return (1);
}

/*
 *key_event kat9ra l key w kat3yet 3la l function li ghatdir dak lmove li 
 kaychbh l event
 * */

int key_event(int key, t_context *ctx)
{
	int stay_or_not;
	if (key == UP_KEY)
		stay_or_not = go_up(&ctx->map);
//	if (key == DOWN_KEY)
//		stay_or_not = go_down(&ctx->map);
//	if (key == LEFT_KEY)
//		stay_or_not = go_left(&ctx->map);
//	if (key == RIGHT_KEY)
//		stay_or_not = go_right(&ctx->map);

//	fflush(stdout);
	return (1);
}
