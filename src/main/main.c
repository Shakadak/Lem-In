/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:23:39 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/11/23 15:49:19 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/structs.h"
#include "inc/lemin.h"
#include "libft/inc/libft.h"
#include <stdlib.h>
#include <stdio.h>



int main()
{
	size_t	ants;
	t_room			*rooms;
	unsigned int	error;
	size_t			rnb;
	t_rb			links;
	t_room			*start;
	t_room			*end;


	error = 0;

	get_anthill(&ants, &rooms, &rnb, &links);
	init_graph(rooms, rnb, links, &error);
	print_graph(rooms, rnb);
	start = find_start_and_error(rooms, rnb, &error);
	if (check_rooms(rooms, rnb, &error))
	{
		end = find_type(END, rooms, rnb);
		printf("found end\n");
		if (!error)
		{
			print_graph(rooms, rnb);
			weight_from_end(end);
			print_graph(start, rnb);
		}
		else
		{
			what_error(error);
		}
	}
	else
	{
		what_error(error);
	}
	return (0);
}
