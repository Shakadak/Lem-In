/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:23:39 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/11/23 14:32:40 by npineau          ###   ########.fr       */
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


	error = 0;

	get_anthill(&ants, &rooms, &rnb, &links);
	init_graph(rooms, rnb, links, &error);
	start = find_start_and_error(rooms, rnb, &error);
	if (error == 0)
	{
		print_graph(rooms, rnb);
		init_weight(start, &error);
		print_graph(start, rnb);
	}
	else
	{
		what_error(error);
	}
	return (0);
}
