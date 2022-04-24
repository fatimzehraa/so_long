/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:58:43 by fael-bou          #+#    #+#             */
/*   Updated: 2022/04/20 00:53:28 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	last_node = NULL;
	while (lst)
	{
		last_node = lst;
		lst = lst->next;
	}
	return (last_node);
}
