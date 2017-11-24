/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:23:39 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/11/24 14:45:50 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/structs.h"
#include "inc/lemin.h"
#include "libft/inc/libft.h"

static void free_room(t_room *room)
{
	free(room->name);
	free(room->conn.b_start);
}

static void free_link(t_link *link)
{
	free(link->fst);
	free(link->sec);
}

int main(void)
{
	size_t			ants;
	t_rb			rooms;
	unsigned int	error;
	size_t			rnb; // TODO remove this thing, it's useless now.
	t_rb			links;
	t_room			*start;
	t_room			*end;

	error = 0;

	get_anthill(&ants, &rooms, &rnb, &links);
	init_graph((t_room*)rooms.head, rooms.used, links, &error);
	rb_iter(links, (void(*)(void *))free_link);
	free(links.b_start);
	start = find_start_and_error((t_room*)rooms.head, rooms.used, &error);
	if (!error && check_rooms((t_room*)rooms.head, rooms.used, &error))
	{
		end = find_type(END, (t_room*)rooms.head, rooms.used);
		weight_from_end(end);
		if (start->weight == -1)
			ft_putendl("ERROR");
		else
			transfer_ants(ants, start);
		what_error(error);
	}
	else
	{
		what_error(error);
	}
	rb_iter(rooms, (void(*)(void *))free_room);
	free(rooms.b_start);
	return (0);
}
