/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_anthill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 10:34:43 by npineau           #+#    #+#             */
/*   Updated: 2017/11/24 14:41:21 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/inc/libft.h"
#include "inc/structs.h"
#include "inc/parsing.h"

int	get_anthill(size_t *ants, t_rb *rooms, size_t *rooms_n, t_rb *links)
{
	int		check;

	if (!rb_new(16, sizeof(t_link), links))
	{
		return (0);
	}
	else if (!rb_new(16, sizeof(t_room), rooms))
	{
		rb_free(links);
		return (0);
	}
	else
	{
		check = parse_anthill(STDIN_FILENO, ants, rooms, links);
		*rooms_n = rooms->used;
	}
	return (check);
}
