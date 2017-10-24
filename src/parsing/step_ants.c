/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:03:42 by npineau           #+#    #+#             */
/*   Updated: 2017/10/24 11:55:40 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/parsing.h"
#include "inc/structs.h"

int	step_ants(int fd, size_t *ants)
{
	t_string	buff;
	int			check;

	if ((check = (get_next_line(fd, &buff) > 0)))
	{
		ft_putendl(buff);
		if (parse_comment(buff))
		{
			free(buff);
			check = (get_next_line(fd, &buff) > 0);
			ft_putendl(buff);
		}
		if (check)
		{
			check = parse_ants(buff, ants);
			free(buff);
		}
	}
	return (check);
}
