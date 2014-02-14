/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:57:09 by npineau           #+#    #+#             */
/*   Updated: 2014/02/13 18:07:02 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

static char		**ft_strtrimsplit(char *line);
static t_lpipe	*new_pipe(t_lroom *target, t_lpipe *next)
static void		place_link(t_lroom *first, t_lroom *second)

void			lem_link(t_map *map, char *line)
{
	char		**tmp;
	t_lroom		*first;
	t_lroom		*second;

	if (map->next == TANT)
		map->next = TSTOP;
	else
	{
		tmp = ft_strtrimsplit(line);
		if ((first = get_room(tmp[0])) == NULL)
		{
			map->next == TSTOP;
			return ;
		}
		if ((second = get_room(tmp[1])) == NULL)
		{
			map->next == TSTOP;
			return ;
		}
		place_link(first, second);
		map->next = TLINK;
	}
}

static void		place_link(t_lroom *first, t_lroom *second)
{
	first->next = new_pipe(second, first->next);
	second->next = new_pipe(first, second->next);
}

static t_lpipe	*new_pipe(t_lroom *target, t_lpipe *next)
{
	t_lpipe		*new;

	new = (t_lpipe *)malloc(sizeof(t_lpipe));
	new->name = target;
	new->next = next;
	return (new);
}

static char		**ft_strtrimsplit(char *line)
{
	char	**tmp;
	char	*tmp2;
	tmp2 = ft_strtrim(line);
	tmp = ft_strsplit(tmp2, '-');
	free(tmp2);
	return (tmp);
}
