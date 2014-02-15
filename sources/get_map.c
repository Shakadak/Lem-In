/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:12:18 by npineau           #+#    #+#             */
/*   Updated: 2014/02/15 13:06:43 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem-in.h"

void	get_map(t_map *map)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
		get(check_line(line), map, line);
}
