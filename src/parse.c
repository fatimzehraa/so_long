/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:29:22 by fael-bou          #+#    #+#             */
/*   Updated: 2022/04/27 05:30:00 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "list.h"
#include "get_next_line.h"

t_list	*parse(char *filename, t_map *map)
{
	t_list	*lines;
	char	*line;
	int		fd;

	lines = NULL;
	fd = open(filename, O_RDONLY);

	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		ft_lstadd_back(&lines, ft_lstnew(line));
	}
	map->lines = lines;
	if (check_map(map))
		return (lines);
	ft_lstclear(&lines, free);
	return (NULL);
}
