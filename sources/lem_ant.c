/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_ant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 18:16:39 by npineau           #+#    #+#             */
/*   Updated: 2014/02/13 19:17:26 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	lem_ant(t_map *map, char *line)
{
	char	*tmp;

	if (map->next != TANT)
		map->next = TSTOP;
	else
	{
		tmp = ft_strtrim(line);
		map->ants = ft_atoi(tmp);
		free(tmp);
		map->next = TBASIC;
	}
}
