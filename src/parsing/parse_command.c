/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:46:24 by npineau           #+#    #+#             */
/*   Updated: 2017/10/19 11:56:13 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/structs.h"

static int	is_hash(char c)
{
	return (c == '#');
}

int	parse_command(char *line, t_room_type *type)
{
	t_pair	pair;
	int		check;

	pair = strspan(is_hash, line);
	check = !ft_strempty(pair.fst) && ft_strequ(pair.fst, "##")
		&& !ft_strempty(pair.snd);
	if (check)
	{
		if (ft_strequ(pair.snd, "start"))
		{
			*type = START;
		}
		else if (ft_strequ(pair.snd, "end"))
		{
			*type = END;
		}
		else
		{
			check = !check;
		}
	}
	free(pair.fst);
	free(pair.snd);
	return (check);
}
