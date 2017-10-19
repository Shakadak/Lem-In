/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:04:00 by npineau           #+#    #+#             */
/*   Updated: 2017/10/19 11:26:43 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"

static int	is_hash(char c)
{
	return (c == '#');
}

int			parse_comment(char *line)
{
	t_pair	pair;
	int		check;

	pair = strspan(is_hash, line);
	check = !ft_strempty(pair.fst) && ft_strnequ(pair.fst, "#");
	free(pair.fst);
	free(pair.snd);
	return (check);
}
