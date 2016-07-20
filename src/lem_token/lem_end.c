/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:40:25 by npineau           #+#    #+#             */
/*   Updated: 2014/02/15 13:23:10 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	lem_end(t_map *map, char *line)
{
	(void)line;
	if (map->next == TLINK)
		map->next = TSTOP;
	else
		map->next = TEND;
}
