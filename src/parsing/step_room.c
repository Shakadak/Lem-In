/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:22:27 by npineau           #+#    #+#             */
/*   Updated: 2017/11/23 15:50:10 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/parsing.h"
#include "inc/structs.h"

static int	step_room(int fd, t_room *room, t_string *last_buffer)
{
	t_string	buff;
	int			check;

	room->type = NORMAL;
	if ((check = (get_next_line(fd, &buff) > 0)))
	{
		ft_putendl(buff);
		while (parse_comment(buff))
		{
			parse_command(buff, &room->type);
			free(buff);
			if (!(check = (get_next_line(fd, &buff) > 0)))
				break ;
			ft_putendl(buff);
		}
		if (check)
		{
			check = parse_room(buff, room);
			if (!check)
				*last_buffer = buff;
			else
				free(buff);
		}
	}
	return (check);
}

int			step_rooms(int fd, t_rb *rooms, t_string *last_buffer)
{
	t_room	room;
	int		check;

	ft_bzero(&room, sizeof(room));
	room.weight = -1;
	if ((check = step_room(fd, &room, last_buffer)))
	{
		rb_new(2, sizeof(t_room *), &room.conn);
		rb_grow_push_back(rooms, &room);
		*last_buffer = NULL;
	}
	return (check);
}
