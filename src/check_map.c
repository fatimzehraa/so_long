/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:05:24 by fael-bou          #+#    #+#             */
/*   Updated: 2022/05/07 15:06:42 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_borders(t_list *lines)
{
	t_list	*cur;
	char	*str;

	cur = lines;
	while (cur)
	{
		str = cur->content;
		if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
			return (0);
		cur = cur->next;
	}
	if (check_wall(lines->content) == 0)
		return (0);
	lines = ft_lstlast(lines);
	return (check_wall(lines->content));
}

int	check_len(t_list *lines)
{
	char	*str;
	int		len;

	str = lines->content;
	len = ft_strlen(str);
	while (lines)
	{
		str = lines->content;
		if (ft_strlen(str) != len)
			return (0);
		lines = lines->next;
	}
	return (1);
}

int	check_components(t_map *map)
{
	int		exit;
	int		start;
	t_list	*lines;
	char	*str;

	exit = 0;
	map->collectibles = 0;
	start = 0;
	lines = map->lines;
	while (lines)
	{
		str = lines->content;
		while (*str)
		{
			exit += (*str == 'E');
			start += (*str == 'P');
			map->collectibles += (*str == 'C');
			if (ft_stri("EPC10", *str) == -1)
				return (0);
			str++;
		}
		lines = lines->next;
	}
	return (exit > 0 && map->collectibles > 0 && start > 0);
}

int	check_map(t_map *map)
{
	return (check_borders(map->lines)
		&& check_components(map) && check_len(map->lines));
}
