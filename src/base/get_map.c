/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:12:18 by npineau           #+#    #+#             */
/*   Updated: 2014/02/17 17:23:25 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/lem-in.h"

void	get_map(t_map *map)
{
	char	*line;
	char	*tline;

	while (get_next_line(0, &line) > 0)
	{
		tline = ft_strtrim(line);
		ft_putendl(tline);
		get(check_line(tline), map, tline);
		free(tline);
		tline = NULL;
		free(line);
		line = NULL;
		if (map->next == TSTOP)
			break ;
	}
}
