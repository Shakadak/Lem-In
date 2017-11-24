/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:27:18 by npineau           #+#    #+#             */
/*   Updated: 2017/11/23 15:37:05 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lemin.h"
#include "inc/structs.h"

t_room	*find_type(
		t_room_type type,
		t_room *rooms,
		int roomnbr)
{
	int		i;
	t_room	*room;

	i = 0;
	room = NULL;
	while (i < roomnbr)
	{
		if (rooms[i].type == type)
		{
			room = &rooms[i];
			break ;
		}
		i += 1;
	}
	return (room);
}
