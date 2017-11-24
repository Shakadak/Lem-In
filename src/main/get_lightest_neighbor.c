/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lightest_neighbor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:30:19 by npineau           #+#    #+#             */
/*   Updated: 2017/11/24 12:25:01 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/structs.h"

t_room	*get_lightest_neighbor(t_room room)
{
	t_room	*lightest;
	t_room	**neighbors;
	size_t	i;

	i = 0;
	neighbors = (t_room **)room.conn.head;
	lightest = NULL;
	while (i < room.conn.used)
	{
		if (lightest == NULL || neighbors[i]->weight < lightest->weight)
		{
			lightest = neighbors[i];
		}
		i += 1;
	}
	return (lightest);
}
