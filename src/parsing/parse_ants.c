/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 13:53:38 by npineau           #+#    #+#             */
/*   Updated: 2017/10/24 11:34:50 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"

int	parse_ants(const char *line, size_t *ret)
{
	t_pair	pair;
	int		check;
	char	*leftover;
	char	*ants_n;

	pair = strspan(ft_isdigit, line);
	ants_n = fst(pair);
	leftover = snd(pair);
	check = !ft_strempty(ants_n) && ft_strempty(leftover);
	if (check)
	{
		*ret = ft_atoi(ants_n);
	}
	free(ants_n);
	free(leftover);
	return (check);
}
