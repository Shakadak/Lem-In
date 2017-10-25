/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:37:24 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/10/25 12:42:59 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "libft.h"
#include "lemin.h"
#include <stdio.h>

void	init_graph(t_room *rooms, size_t roomnbr, t_rb links, unsigned int *error)
{
	size_t	cnt;
	int		ok;
	t_room	*r1;
	t_link	l;

	while (rb_pop_front(&links, &l))
	{
		if (!ft_strcmp(l.fst, l.sec))
			continue;
		cnt = 0;
		ok = 0;
		r1 = NULL;
		while (cnt < roomnbr)
		{
			if (!ft_strcmp(rooms[cnt].name, l.fst)
					|| !ft_strcmp(rooms[cnt].name, l.sec))
			{
				if (r1 == NULL)
					r1 = &rooms[cnt];
				else
				{
					go_link(r1, &rooms[cnt]);
					ok++;
				}
			}
			cnt++;
		}
		if (!ok)
			*error += LNK_ERR;
	}
}

//t_room	*find_start_and_error(t_room *rooms, int roomnbr, unsigned int *error)
//{
//	int		cnt;
//	int		start;
//	int		end;
//	t_room	*sroom;
//
//	cnt = 0;
//	start = 0;
//	end = 0;
//	while (cnt < roomnbr)
//	{
//		if (rooms[cnt].type == START)
//			sroom = &rooms[start++];
//		else if (rooms[cnt].type == END)
//			end++;
//		cnt++;
//	}
//	*error += (start != 1) ? SRT_ERR : 0;
//	*error += (end < 1) ? END_ERR : 0;
//	return (sroom);
//}

void	go_link(t_room *r1, t_room *r2)
{
	rb_grow_push_back(&r1->conn, &r2);
	rb_grow_push_back(&r2->conn, &r1);
//	ft_lstadd(&r1->conn, ft_lstnew(r2, sizeof(r2)));
//	ft_lstadd(&r2->conn, ft_lstnew(r1, sizeof(r1)));
}
