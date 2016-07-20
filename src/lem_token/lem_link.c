/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:57:09 by npineau           #+#    #+#             */
/*   Updated: 2014/02/22 17:38:48 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem-in.h"
#include "libft.h"

static t_lpipe	*new_pipe(t_lroom *target, t_lpipe *next, int d);
static void		place_link(t_lroom *first, t_lroom *second);

void			lem_link(t_map *map, char *line)
{
	char		**tmp;
	t_lroom		*first;
	t_lroom		*second;

	if (map->next == TANT)
		map->next = TSTOP;
	else
	{
		tmp = ft_strtrimsplit(line, '-');
		if ((first = get_room(map->map, tmp[0])) == NULL)
		{
			map->next = TLINK;
			return ;
		}
		if ((second = get_room(map->map, tmp[1])) == NULL)
		{
			map->next = TLINK;
			return ;
		}
		place_link(first, second);
		map->next = TLINK;
	}
}

static void		place_link(t_lroom *first, t_lroom *second)
{
	first->link = new_pipe(second, first->link, 0);
	second->link = new_pipe(first, second->link, 1);
}

static t_lpipe	*new_pipe(t_lroom *target, t_lpipe *next, int d)
{
	t_lpipe		*new;

	new = (t_lpipe *)malloc(sizeof(t_lpipe));
	new->name = target;
	new->next = next;
	new->duplicate = d;
	return (new);
}

char			**ft_strtrimsplit(char *line, char c)
{
	char		**tmp;
	char		*tmp2;

	tmp2 = ft_strtrim(line);
	tmp = ft_strsplit(tmp2, c);
	free(tmp2);
	return (tmp);
}