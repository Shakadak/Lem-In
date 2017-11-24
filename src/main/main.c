/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:23:39 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/11/24 12:28:51 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/structs.h"
#include "inc/lemin.h"
#include "libft/inc/libft.h"



int main(void)
{
	size_t			ants;
	t_room			*rooms;
	unsigned int	error;
	size_t			rnb;
	t_rb			links;
	t_room			*start;
	t_room			*end;

	error = 0;

	unsigned int banana;
	get_anthill(&ants, &rooms, &rnb, &links);
	init_graph(rooms, rnb, links, &error);
	start = find_start_and_error(rooms, rnb, &error);
	if ((banana = check_rooms(rooms, rnb, &error)))
	{
		end = find_type(END, rooms, rnb);
		if (!error)
		{
			weight_from_end(end);
			if (start->weight == -1)
				ft_putendl("ERROR");
			else
				transfer_ants(ants, start);
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
