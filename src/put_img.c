/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:27:10 by fael-bou          #+#    #+#             */
/*   Updated: 2022/04/25 03:37:09 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "list.h"
#include "get_next_line.h"

void put_img(t_context ctx, int x, int y, void *img)
{
	mlx_put_image_to_window(ctx.mlx, ctx.win, img, x, y);
}
