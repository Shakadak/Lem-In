/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:12:45 by npineau           #+#    #+#             */
/*   Updated: 2014/02/22 16:45:19 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem-in.h"
#include "libft.h"

static t_lpipe	*new_elem(t_lroom *current);
static void		move_ant(t_lpipe *room, int ant, int max_ant, int space);
static void		get_path(t_lroom *room, t_lpipe *begin);

void			display_ants(t_map *map)
{
	t_lpipe		*road;
	t_lroom		*tmp;
	int			ant;

	road = new_elem(map->start);
	get_path(map->start, road);
	tmp = map->start;
	ant = 1;
	while (ant <= map->ants + map->start->weight)
	{
		move_ant(road, ant++, map->ants, 0);
		ft_putchar('\n');
	}
}

static void		move_ant(t_lpipe *room, int ant, int max_ant, int space)
{
	if (!room || !ant)
		return ;
	if (ant <= max_ant)
	{
		move_ant(room->next, ant - 1, max_ant, space + 1);
		ft_putchar('L');
		ft_putnbr(ant);
		ft_putchar('-');
		ft_putstr(room->name->name);
		if (space)
			ft_putchar(' ');
	}
	else
		move_ant(room->next, ant - 1, max_ant, space);
}

static void		get_path(t_lroom *room, t_lpipe *begin)
{
	t_lpipe		*tmp;
	t_lroom		*low;

	low = room;
	while (room->type != TEND)
	{
		tmp = room->link;
		while (tmp)
		{
			low = (tmp->name->weight < low->weight ? tmp->name : low);
			tmp = tmp->next;
		}
		begin->next = new_elem(low);
		room = low;
		begin = begin->next;
	}
}

static t_lpipe	*new_elem(t_lroom *current)
{
	t_lpipe		*new;

	new = (t_lpipe *)malloc(sizeof(t_lpipe));
	new->name = current;
	new->next = NULL;
	new->duplicate = 0;
	return (new);
}
