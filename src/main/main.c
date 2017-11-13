/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:23:39 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/10/25 13:01:49 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/structs.h"
#include "inc/lemin.h"
#include "libft/inc/libft.h"
#include <stdlib.h>
#include <stdio.h>

t_room	*test_create_rooms()
{
	t_room	*rooms;

	rooms = (t_room *)malloc(sizeof(t_room) * 4);
	if (!rooms)
		return (NULL);

	rooms[0].name = ft_strdup("0");
	rooms[0].type = START;
	rooms[0].weight = -1;
	rb_new(2, sizeof(t_room *), &rooms[0].conn);

	rooms[1].name = ft_strdup("1");
	rooms[1].type = NORMAL;
	rooms[1].weight = -1;
	rb_new(2, sizeof(t_room *), &rooms[1].conn);

	rooms[2].name = ft_strdup("2");
	rooms[2].type = NORMAL;
	rooms[2].weight = -1;
	rb_new(2, sizeof(t_room *), &rooms[2].conn);

	rooms[3].name = ft_strdup("3");
	rooms[3].type = END;
	rooms[3].weight = -1;
	rb_new(2, sizeof(t_room *), &rooms[3].conn);

	return (rooms);
}

int main()
{
	//size_t	ants;
	t_room			*rooms;
	unsigned int	error;
	size_t			rnb;
	t_rb			links;
	t_link			link;
	t_room			*start;

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

	rooms = test_create_rooms();
	init_graph(rooms, rnb, links, &error);
	if (error != 0)
		what_error(error);
	print_graph(rooms, rnb);
	start = find_start_and_error(rooms, rnb, &error);
	if (error != 0)
		what_error(error);
	printf("preinit weight\n");
	init_weight(start, &error);
	print_graph(start, rnb);

//	printf("\n----------\n\n");
//	if (get_anthill(&ants, &rooms, &rnb, &links))
//	{
//		init_graph(rooms, rnb, links, &error);
//		if (error == 0)
//		{
//			print_graph(rooms, rnb);
//		}
//	}
//	return (0);
}
