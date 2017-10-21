/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathanael <npineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 12:46:52 by nathanael         #+#    #+#             */
/*   Updated: 2017/10/21 15:06:02 by nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/parsing.h"

int	parse_nat(t_string in, t_string *out, int *nat)
{
	t_pair	pair;
	int		check;

	pair = strspan(ft_isdigit, in);
	check = !ft_strempty(pair.fst);
	if (check)
	{
		*nat = ft_atoi(pair.fst);
	}
	free(pair.fst);
	*out = pair.snd;
	return (check);
}

int	parse_int(t_string in, t_string *out, int *integer)
{
	int		check;
	int		mod;
	size_t	start;
	int		nat;

	mod = 1;
	start = 0;
	if (in[0] == '-')
	{
		mod = -1;
		start = 1;
	}
	else if (in[0] == '+')
	{
		start = 1;
	}
	if ((check = parse_nat(&in[start], out, &nat)))
	{
		*integer = mod * nat;
	}
	return check;
}
