/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:37:24 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/10/19 13:31:28 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "libft.h"
#include "lem-in.h"
#include <stdio.h>

int		init_graph(t_room *rooms, int roomnbr, t_rb links)
{
	int		i;
	int		j;
	int		ok;
	t_room	*r1;
	t_link	l;

	i = 0;
	while (rb_pop_front(&links, &l))
	{
		if (!ft_strcmp(l.fst, l.sec))
			continue;
		j = 0;
		ok = 0;
		r1 = NULL;
		while (j < roomnbr)
		{
			if (!ft_strcmp(rooms[j].name, l.fst)
					|| !ft_strcmp(rooms[j].name, l.sec))
			{
				if (r1 == NULL)
					r1 = &rooms[j];
				else
				{
					go_link(r1, &rooms[j]);
					ok++;
				}
			}
			j++;
		}
		if (!ok)
			return ok;
	}
	return 1;
}

void	go_link(t_room *r1, t_room *r2)
{
	ft_lstadd(&r1->conn, ft_lstnew(&r2, sizeof(r2)));
	ft_lstadd(&r2->conn, ft_lstnew(&r1, sizeof(r1)));
}
