/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 00:07:08 by fael-bou          #+#    #+#             */
/*   Updated: 2022/05/10 17:12:32 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "list.h"

# define SIDE_SQUARE 49

typedef struct s_map
{
	int				height;
	int				width;
	t_list			*lines;
	void			*wall;
	void			*coin;
	void			*character;
	void			*exit;
	void			*enemy;
	int				collectibles;
	unsigned int	count;
}				t_map;

typedef struct s_context
{
	void	*mlx;
	void	*win;
	t_map	map;
}				t_context;

enum e_keys {
	UP_KEY = 13,
	DOWN_KEY = 1,
	LEFT_KEY = 0,
	RIGHT_KEY = 2,
	ESC_KEY = 53,
};

int		check_map(t_map *map);
t_list	*parse(char *filename, t_map *map);
void	put_img(t_context ctx, int x, int y, void *img);
void	draw(t_context *ctx);
int		key_event(int key, t_context *ctx);
int		ft_stri(char *str, char c);
int		end_with(char *s1, char *s2);
int		args_err(int argc, char *argv[]);
void	print_error(char *msg);
void	free_ctx(t_context *ctx);
void	init_ctx(t_context *ctx);
void	print_moves(t_context *ctx);

#endif
