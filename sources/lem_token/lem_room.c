/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 14:29:41 by npineau           #+#    #+#             */
/*   Updated: 2014/02/21 18:05:36 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem-in.h"
#include "libft.h"
#include "parse.h"

static void		change_type(t_map *map, t_lroom *current);
static void		free_tab(char ***tab);
static t_lroom	*new_room(char **src, t_lroom *current);
static void		new_coo(char **src, t_lroom *current);

void	lem_room(t_map *map, char *line)
{
	char	**tmp;
	t_lroom	*current;

	if (map->next == TLINK || map->next == TANT)
		map->next = TSTOP;
	else
	{
		tmp = ft_strtrimsplit(line, ' ');
		if (full_digit(tmp[1]) && full_digit(tmp[2]))
		{
			if ((current = get_room(map->map, tmp[0])) == NULL)
			{
				map->map = new_room(tmp, map->map);
				current = map->map;
			}
			else
				new_coo(tmp, current);
			if (map->next == TSTART || map->next == TEND)
				change_type(map, current);
			map->next = TBASIC;
		}
		else
			lem_error(map, tmp[0]);
		free_tab(&tmp);
	}
}

static t_lroom	*new_room(char **src, t_lroom *current)
{
	t_lroom		*new;

	new = (t_lroom *)malloc(sizeof(t_lroom));
	new->next = current;
	new->name = ft_strdup(src[0]);
	new->type = TBASIC;
	new->weight = -1;
	new_coo(src, new);
	new->link = NULL;
	return (new);
}

static void		new_coo(char **src, t_lroom *current)
{
	current->coo.x = ft_atoi(src[1]);
	current->coo.y = ft_atoi(src[2]);
}

static void		change_type(t_map *map, t_lroom *current)
{
	if (map->next == TSTART)
	{
		if (map->start)
			map->start->type = TBASIC;
		current->type = TSTART;
		map->start = current;
	}
	else if (map->next == TEND)
	{
		if (map->end)
			map->end->type = TBASIC;
		current->type = TEND;
		map->end = current;
	}
}

static void		free_tab(char ***tab)
{
	if (*tab)
	{
		if (**tab)
		{
			free((*tab)[0]);
			free((*tab)[1]);
			free((*tab)[2]);
		}
		free(*tab);
		*tab = NULL;
	}
}
