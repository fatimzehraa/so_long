/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:29:22 by fael-bou          #+#    #+#             */
/*   Updated: 2022/05/07 15:02:04 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*get_lines(int fd)
{
	t_list	*lines;
	char	*line;
	t_list	*new_node;

	lines = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		new_node = ft_lstnew(line);
		if (new_node == NULL)
		{
			ft_lstclear(&lines, free);
			return (NULL);
		}
		ft_lstadd_back(&lines, new_node);
	}
	return (lines);
}

t_list	*parse(char *filename, t_map *map)
{
	t_list	*lines;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error("failed to open the file");
		return (NULL);
	}
	lines = get_lines(fd);
	if (lines == NULL)
	{
		print_error("failed to read the file");
		return (NULL);
	}
	close(fd);
	map->lines = lines;
	if (check_map(map))
		return (lines);
	print_error("the map is invalid");
	ft_lstclear(&lines, free);
	return (NULL);
}
