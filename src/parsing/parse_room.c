/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:34:29 by npineau           #+#    #+#             */
/*   Updated: 2017/10/21 18:13:27 by nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/structs.h"
#include "inc/parsing.h"

static int	is_invalid_fst(char c)
{
	return (c == 'L' || c == '#' || ft_isspace(c));
}

static int	parse_lexed_name(t_string buff, t_string *leftover, t_string *name)
{
	t_pair	pair;

	if (is_invalid_fst(buff[0]))
	{
		return (0);
	}
	pair = strbreak(ft_isspace, buff);
	*name = pair.fst;
	*leftover = pair.snd;
	pair = strspan(ft_isspace, *leftover);
	free(pair.fst);
	*leftover = pair.snd;
	return (1);
}

static int	parse_lexed_int(t_string in, t_string *out, int *integer)
{
	int 		check;
	t_string	tmp;

	if ((check = parse_int(in, &tmp, integer)))
	{
		check = spaces1(tmp, out);
		free(tmp);
	}
	return (check);
}

int	parse_room(char *line, t_room *room)
{
	int			check;
	t_string	tmp;
	t_string	tmp2;

	check = parse_lexed_name(line, &tmp, &room->name);
	if (check)
	{
		check = parse_lexed_int(tmp, &tmp2, &room->coord.x);
		free(tmp);
		tmp = NULL;
		if (check)
		{
			check = parse_int(tmp2, &tmp, &room->coord.y);
			free(tmp2);
			check = check && ft_strempty(tmp);
			free(tmp);
		}
	}
	if (!check)
	{
		free(room->name);
		room->name = NULL;
	}
	return check;
}
