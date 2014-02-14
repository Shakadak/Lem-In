/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:32:20 by npineau           #+#    #+#             */
/*   Updated: 2014/02/13 15:39:10 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	lem_start(t_map *map, char *line)
{
	(void)line;
	if (map->next == TLINK)
		map->next = TSTOP;
	else
		map->next = TSTART;
}
