/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:05:24 by fael-bou          #+#    #+#             */
/*   Updated: 2022/04/22 01:57:05 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "list.h"
#include "so_long.h"

char *get_str(t_list *line)
{
	return ((char *)line->content);
}

int check_borders(t_list *lines)
{
	t_list *cur;
	char	*str;
	int i;

	cur = lines;
	while(cur)
	{
		str = get_str(cur);
		if (str[0] != '1' || str[ft_strlen(cur->content) - 1] != '1')
			return (0);
		cur = cur->next;
	}
	i = 0;
	while (get_str(lines)[i])
	{
		if (get_str(lines)[i] != '1')
			return (0);
		i++;
	}
	lines = ft_lstlast(lines);
	i = 0;
	while (get_str(lines)[i])
	{
		if (get_str(lines)[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int check_len(t_list *lines)
{
	char *str;
	int len;

	str = get_str(lines);
	len = ft_strlen(str);
	while (lines) 
	{
		str = get_str(lines);
		if (ft_strlen(str) != len)
			return (0);
		lines = lines->next;
	}
	return (1);
}

int check_components(t_list *lines)
{
	int exit;
	int col;
	int start;
	char *str;

	exit = 0;
	col = 0;
	start = 0;
	while (lines) 
	{
		str = lines->content;
		while (*str)
		{
			if (*str == 'E')
				exit++;
			else if (*str == 'P')
				start++;
			else if (*str == 'C')
				col++;
			else if (*str == '1' || *str == '0')
				;
			else
				return (0);
			str++;
		}
		lines = lines->next;
	}
	return (exit > 0 && col > 0 && start > 0);
}

int check_map(t_list *lines)
{
	return (check_borders(lines) && check_components(lines) && check_len(lines));
}
