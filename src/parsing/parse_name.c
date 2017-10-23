/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathanael <npineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 10:35:21 by nathanael         #+#    #+#             */
/*   Updated: 2017/10/23 10:17:02 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/structs.h"
#include "inc/parsing.h"

static int	is_invalid_fst(char c)
{
	return (c == 'L' || c == '#' || c == '-' || ft_isspace(c));
}

static int	is_valid_name_char(char c)
{
	return (c != '-' && !ft_isspace(c));
}

int			parse_name(t_string in, t_string *out, t_string *name)
{
	t_pair	pair;
	int		check;

	if (is_invalid_fst(in[0]))
	{
		return (0);
	}
	pair = strspan(is_valid_name_char, in);
	if ((check = ft_strempty(pair.fst)))
	{
		free(pair.fst);
		free(pair.snd);
	}
	else
	{
		*name = pair.fst;
		*out = pair.snd;
	}
	return (check);
}

int			parse_lexed_name(t_string buff, t_string *leftover, t_string *name)
{
	int			check;
	t_string	tmp;
	t_string	tmp2;

	if ((check = parse_name(buff, &tmp, &tmp2)))
	{
		if ((check = spaces1(tmp, leftover)))
		{
			*name = tmp2;
		}
		else
		{
			free(tmp2);
		}
		free(tmp);
	}
	return (check);
}
