/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:39:10 by npineau           #+#    #+#             */
/*   Updated: 2017/10/23 15:05:43 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/parsing.h"
#include "inc/structs.h"

static int	step_link(int fd, t_link *link, t_string *last_buffer)
{
	t_string	buff;
	int			check;

	buff = *last_buffer;
	if ((check = buff != NULL ? 1 : (get_next_line(fd, &buff) > 0)))
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
			check = parse_link(buff, link);
			free(buff);
		}
	}
	return (check);
}

int			step_links(int fd, t_rb *links, t_string *last_buffer)
{
	t_link	link;
	int		check;

	if ((check = step_link(fd, &link, last_buffer)))
	{
		if (rb_full(*links))
		{
			rb_resize(links, links->capacity * 2);
		}
		rb_push_back(links, &link);
		*last_buffer = NULL;
	}
	return (check);
}
