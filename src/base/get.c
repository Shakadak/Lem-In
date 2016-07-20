/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:14:21 by npineau           #+#    #+#             */
/*   Updated: 2014/02/15 17:36:25 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem-in.h"
#include "inc/parse.h"

void		get(int token, t_map *map, char *line)
{
	static t_func	func[] = {
		&lem_error,
		&lem_start,
		&lem_end,
		&lem_comment,
		&lem_link,
		&lem_ant,
		&lem_room
	};

	func[token](map, line);
}
