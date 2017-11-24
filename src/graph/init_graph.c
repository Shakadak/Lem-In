/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:37:24 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/11/24 14:40:00 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "libft.h"
#include "lemin.h"

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
			*error |= LNK_ERR;
	}
}

void	recursive_weight(t_rb *queu, int weight, size_t cnt)
{
	t_room	*room;
	t_room	**tco;
	size_t	co;
	size_t	nxt;

	nxt = 0;
	while (cnt > 0)
	{
		rb_pop_front(queu, &room);
		cnt--;
		if (room->weight > 0 || room->type == START)
			continue;
		room->weight = weight;
		co = 0;
		tco = (t_room **)room->conn.head;
		while (co < room->conn.used)
			rb_grow_push_back(queu, &tco[co++]);
		nxt += co;
	}
	if (queu->used > 0 && nxt > 0)
		recursive_weight(queu, weight+1, nxt);
}

void	init_weight(t_room *start, unsigned int *error)
{
	size_t	co;
	t_rb	queu;
	t_room	**tco;

	co = 0;
	if (start->conn.used < 1)
	{
		*error |= STC_ERR;
		return;
	}
	rb_new(start->conn.used, sizeof(t_room *), &queu);
	tco = (t_room **)start->conn.head;
	while (co < start->conn.used)
		rb_push_back(&queu, &tco[co++]);
	start->weight = 0;
	recursive_weight(&queu, 1, start->conn.used);
}

t_room	*find_start_and_error(t_room *rooms, int roomnbr, unsigned int *error)
{
	int		cnt;
	int		start;
	int		end;
	t_room	*sroom;

	cnt = 0;
	start = 0;
	end = 0;
	while (cnt < roomnbr)
	{
		if (rooms[cnt].type == START)
		{
			sroom = &rooms[cnt];
			start++;
		}
		else if (rooms[cnt].type == END)
			end++;
		cnt++;
	}
	*error |= (start != 1) ? SRT_ERR : 0;
	*error |= (end < 1) ? END_ERR : 0;
	return (sroom);
}

void	go_link(t_room *r1, t_room *r2)
{
	rb_grow_push_back(&r1->conn, &r2);
	rb_grow_push_back(&r2->conn, &r1);
}
