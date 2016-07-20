/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 17:32:03 by npineau           #+#    #+#             */
/*   Updated: 2014/02/22 16:49:56 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/lem-in.h"
#include "libft/inc/libft.h"

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
	put_weight(map->end, 0);
	if (!map->start || map->start->weight == -1)
	{
		ft_putendl("ERROR");
		return (-1);
	}
	display_map(map);
	ft_putchar('\n');
	display_ants(map);
	return (0);
}
