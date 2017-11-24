/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:04:20 by npineau           #+#    #+#             */
/*   Updated: 2017/11/24 12:32:18 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> ////////////
#include "inc/lemin.h"

static void	show_ant_move(t_ant *ant, char **str)
{
	asprintf(str, "L%lu-%s", ant->id, ant->room->name);
}

void		print_ants(t_rb ants)
{
	size_t	len;
	char	*buff;
	t_rb	moves;

	rb_map(ants, sizeof(char *), (void(*)(void*, void*))show_ant_move, &moves);
	buff = mstr_join_with(" ", (char**)moves.head, moves.used, &len);
	write(1, buff, len);
	write(1, "\n", 1);
}

void		step_forward(t_ant *ant)
{
	ant->room = get_lightest_neighbor(*ant->room);
}

void		transfer_ants(size_t ants, t_room *start)
{
	t_rb	ants_q;
	t_ant	ant;

	rb_new(ants, sizeof(t_ant), &ants_q);
	ant.id = 1;
	ant.room = get_lightest_neighbor(*start);
	rb_push_back(&ants_q, &ant);
	print_ants(ants_q);
	while (!rb_empty(ants_q))
	{
		rb_iter(ants_q, (void(*)(void*))step_forward);
		if (ant.id < ants)
		{
			ant.id += 1;
			rb_push_back(&ants_q, &ant);
		}
		print_ants(ants_q);
		if (((t_ant *)ants_q.head)->room->type == END)
		{
			rb_pop_front(&ants_q, NULL);
		}
	}
}
