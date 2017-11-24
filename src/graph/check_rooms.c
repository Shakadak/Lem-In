/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:39:44 by npineau           #+#    #+#             */
/*   Updated: 2017/11/24 07:43:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lemin.h"

int	check_rooms(t_room *rooms, size_t qty, unsigned int *err)
{
	size_t	i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	while (i < qty)
	{
		if (rooms[i].type == START)
		{
			start += 1;
		}
		else if (rooms[i].type == END)
		{
			end += 1;
		}
		i += 1;
	}
	*err |= (start != 1 ? SRT_ERR : 0);
	*err |= (end != 1 ? END_ERR : 0);
	return (!*err);
}
