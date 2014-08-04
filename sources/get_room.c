/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 14:29:32 by npineau           #+#    #+#             */
/*   Updated: 2014/02/15 15:03:27 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

t_lroom	*get_room(t_lroom *room, char *src)
{
	if (room == NULL)
		return (NULL);
	if (ft_strequ(room->name, src))
		return (room);
	return (get_room(room->next, src));
}
