/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathanael <npineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 10:21:26 by nathanael         #+#    #+#             */
/*   Updated: 2017/10/22 14:10:30 by nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "inc/parsing.h"
#include "inc/structs.h"

int	parse_char(char c, t_string in, t_string *out, char *c_out)
{
	int	check;

	if ((check = (in[0] == c)))
	{
		if (c_out != NULL)
		{
			*c_out = c;
		}
		*out = ft_strdup(&in[1]);
	}
	return check;
}

int	parse_link(t_string buff, t_link *link)
{
	int			check;
	t_string	tmp;
	t_string	tmp2;

	if ((check = parse_name(buff, &tmp, &link->fst)))
	{
		if ((check = (tmp[0] ==  '-')))
		{
			if ((check = parse_name(tmp + 1, &tmp2, &link->sec)))
			{
				free(tmp);
				if (!(check = ft_strempty(tmp2)))
				{
					ft_strdel(&link->fst);
					ft_strdel(&link->sec);
				}
				free(tmp2);
			}
			else
				ft_strdel(&link->fst);
		}
		else
			ft_strdel(&link->fst);
	}
	return check;
}
