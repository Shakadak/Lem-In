/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_anthill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:19:10 by npineau           #+#    #+#             */
/*   Updated: 2017/11/23 09:38:04 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/parsing.h"
#include "inc/structs.h"

static int	step_end_of_input(int fd, t_string last_buffer)
{
	if (last_buffer != NULL)
	{
		free(last_buffer);
		return (0);
	}
	else if (get_next_line(fd, &last_buffer) > 0)
	{
		free(last_buffer);
		return (0);
	}
	else
	{
		return (1);
	}
}

static int	step_links_go(int fd, t_rb *links, t_string last_buffer)
{
	while (step_links(fd, links, &last_buffer))
		;
	return (step_end_of_input(fd, last_buffer));
}

static int	step_rooms_go(int fd, t_rb *rooms, t_rb *links)
{
	t_string	last_buffer;

	last_buffer = NULL;
	while (step_rooms(fd, rooms, &last_buffer))
		;
	return (step_links_go(fd, links, last_buffer));
}

static int	step_ants_go(int fd, size_t *ants, t_rb *rooms, t_rb *links)
{
	if (step_ants(fd, ants))
	{
		return (step_rooms_go(fd, rooms, links));
	}
	else
	{
		return (0);
	}
}

int			parse_anthill(int fd, size_t *ants, t_rb *rooms, t_rb *links)
{
	int	check;

	check = step_ants_go(fd, ants, rooms, links);
	return (check);
}
