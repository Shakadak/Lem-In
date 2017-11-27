/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_from_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:50:51 by npineau           #+#    #+#             */
/*   Updated: 2017/11/27 08:46:39 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/lemin.h"
#include "inc/structs.h"
#include "libft/inc/libft.h"

void	weight_from_end(t_room *end)
{
	t_rb	queue;
	t_room	*room;
	t_room	**rs;
	size_t	i;

	end->weight = 0;
	rb_new(16, sizeof(t_room *), &queue);
	rb_grow_push_back(&queue, &end);
	while (rb_pop_front(&queue, &room))
	{
		i = 0;
		rs = (t_room **)room->conn.head;
		while (i < room->conn.used)
		{
			if (rs[i]->weight == -1)
			{
				rs[i]->weight = room->weight + 1;
				rb_grow_push_back(&queue, &rs[i]);
			}
			i += 1;
		}
	}
	free(queue.b_start);
}
