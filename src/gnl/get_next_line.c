/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:50:51 by fael-bou          #+#    #+#             */
/*   Updated: 2022/03/22 18:43:05 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include<stdio.h>

char	*get_until_newline(int fd, char *over_line)
{
	int		read_ret;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (!is_new_line(over_line))
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == 0)
			break ;
		if (read_ret == -1)
		{
			free(buffer);
			free(over_line);
			return (NULL);
		}
		buffer[read_ret] = 0;
		over_line = ft_strjoin(over_line, buffer);
		if (over_line == NULL)
			break ;
	}
	free(buffer);
	return (over_line);
}

char	*ft_get_line(char *str)
{
	int		line_len;
	char	*line;

	if (str[0] == '\0')
		return (NULL);
	line_len = is_new_line(str);
	if (line_len == 0)
		line_len = ft_strlen(str);
	line = malloc((line_len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strncpy(line, str, line_len);
	return (line);
}

char	*ft_get_rest(char *str)
{
	int		line_len;
	int		rest_len;
	char	*rest;

	if (str[0] == '\0')
		return (NULL);
	line_len = is_new_line(str);
	if (line_len == 0)
		line_len = ft_strlen(str);
	rest_len = ft_strlen(str + line_len);
	rest = malloc(sizeof(char) * (rest_len + 1));
	if (rest == NULL)
		return (NULL);
	ft_strncpy(rest, str + line_len, rest_len);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*str;
	char		*line;

	str = get_until_newline(fd, rest);
	if (str == NULL)
	{
		free(rest);
		return (NULL);
	}
	line = ft_get_line(str);
	rest = ft_get_rest(str);
	free(str);
	return (line);
}
