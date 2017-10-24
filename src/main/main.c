/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:23:39 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/10/19 13:31:10 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "lem-in.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_room	*test_create_rooms()
{
	t_room	*rooms;

	rooms = (t_room *)malloc(sizeof(t_room) * 4);
	if (!rooms)
		return (NULL);
	rooms[0].name = ft_strdup("0");
	rooms[1].name = ft_strdup("1");
	rooms[2].name = ft_strdup("2");
	rooms[3].name = ft_strdup("3");
	return (rooms);
}

int main()
{
	t_room			*rooms;
	int				rnb;
	unsigned int	error;
	t_rb			links;
	t_link			link;
	//t_room			*start;

	//t_link	l;

	error = 0;
	rnb = 4;
	rb_new(5, sizeof(t_link), &links);

	link.fst = ft_strdup("0");
	link.sec = ft_strdup("3");
	rb_push_back(&links, &link);
	link.fst = ft_strdup("0");
	link.sec = ft_strdup("2");
	rb_push_back(&links, &link);
	link.fst = ft_strdup("1");
	link.sec = ft_strdup("3");
	rb_push_back(&links, &link);
	link.fst = ft_strdup("1");
	link.sec = ft_strdup("2");
	rb_push_back(&links, &link);
	link.fst = ft_strdup("2");
	link.sec = ft_strdup("3");
	rb_push_back(&links, &link);

	//rb_pop_front(&links, &l);

	rooms = test_create_rooms();
	init_graph(rooms, rnb, links, &error);
	if (error != 0)
		what_error(error);
	print_graph(rooms, rnb);
	//start = find_start_and_error(rooms, rnb, &error);
	if (error != 0)
		what_error(error);
}
