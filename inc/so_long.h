/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 00:07:08 by fael-bou          #+#    #+#             */
/*   Updated: 2022/04/27 05:21:01 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "list.h"

# define SIDE_SQUARE 49

typedef struct s_map
{
	int		height;
	int		width;
	t_list	*lines;
	void	*wall;
	void	*coin;
	void	*character;
	void	*exit;
	int		collectibles;
}	t_map;

typedef struct s_context
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_context;

enum e_keys {
	UP_KEY = 13,
	DOWN_KEY = 1,
	LEFT_KEY = 0,
	RIGHT_KEY = 2,
};

int		check_map(t_map *map);
t_list	*parse(char *filename, t_map *map);
void	put_img(t_context ctx, int x, int y, void *img);
void	draw(t_context *ctx);
int		key_event(int key, t_context *ctx);
int ft_stri(char *str, char c);

#endif
