/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_anthill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 10:34:43 by npineau           #+#    #+#             */
/*   Updated: 2017/11/23 14:36:41 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/inc/libft.h"
#include "inc/structs.h"
#include "inc/parsing.h"

int	get_anthill(size_t *ants, t_room **rooms, size_t *rooms_n, t_rb *links)
{
	int		check;
	t_rb	room_b;

	if (!rb_new(16, sizeof(t_link), links))
	{
		return (0);
	}
	else if (!rb_new(16, sizeof(t_room), &room_b))
	{
		rb_free(links);
		return (0);
	}
	else
	{
		check = parse_anthill(STDIN_FILENO, ants, &room_b, links);
		*rooms = (t_room *)room_b.head;
		*rooms_n = room_b.used;
	}
	return (check);
}
