/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 09:46:06 by fael-bou          #+#    #+#             */
/*   Updated: 2022/05/07 15:07:09 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
}

int	args_err(int argc, char *argv[])
{
	if (argc < 2)
	{
		print_error("please add the map file.ber to run the game");
		return (1);
	}
	if (argc > 2)
	{
		print_error("too many arguments!");
		return (1);
	}
	if (!end_with(argv[1], ".ber"))
	{
		print_error("your filename should have the extension .ber");
		return (1);
	}
	return (0);
}
