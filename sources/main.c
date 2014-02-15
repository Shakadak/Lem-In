/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 17:32:03 by npineau           #+#    #+#             */
/*   Updated: 2014/02/15 18:08:54 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem-in.h"

int		main(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->ants = 0;
	map->start = NULL;
	map->end = NULL;
	map->map = NULL;
	map->next = TANT;
	get_map(map);
	display_map(map);
	return (0);
}
