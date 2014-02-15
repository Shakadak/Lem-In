/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:14:21 by npineau           #+#    #+#             */
/*   Updated: 2014/02/15 13:12:09 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "parse.h"

static void	exe_func(t_func call, t_map *map, char *line);

void		get(int token, t_map *map, char *line)
{
	static t_func	func[]=
	{
		&lem_error,
		&lem_start,
		&lem_end,
		&lem_comment,
		&lem_link,
		&lem_ant,
		&lem_room
	};

	exe_func(func[token], map, line);
}

static void	exe_func(t_func call, t_map *map, char *line)
{
	call(map, line);
}
