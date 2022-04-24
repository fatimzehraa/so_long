/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:27:10 by fael-bou          #+#    #+#             */
/*   Updated: 2022/04/24 03:53:38 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "list.h"
#include "get_next_line.h"

void put_img(t_context ctx, int x, int y, char *relative_path)
{
	//char *relative_path;
	void *img;
	int side;

	side = 30;
	//relative_path = "P.xpm";
	//void *img = mlx_new_image(mlx, 1920, 1080);
	img = mlx_xpm_file_to_image(ctx.mlx, relative_path, &side, &side);
	mlx_put_image_to_window(ctx.mlx, ctx.win, img, x, y);
}
