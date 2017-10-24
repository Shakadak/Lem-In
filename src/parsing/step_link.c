/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:39:10 by npineau           #+#    #+#             */
/*   Updated: 2017/10/24 13:39:40 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/parsing.h"
#include "inc/structs.h"

static int	step_comment(int fd, t_string *buffer, t_string *last_buffer)
{
	int	check;

	check = 1;
	if (parse_comment(*buffer))
	{
		free(*buffer);
		*last_buffer = NULL;
		if ((check = (get_next_line(fd, buffer) > 0)))
		{
			ft_putendl(*buffer);
			*last_buffer = *buffer;
		}
	}
	return (1);
}

static int	step_link(int fd, t_link *link, t_string *last_buffer)
{
	t_string	buff;
	int			check;

	buff = *last_buffer;
	if ((check = buff != NULL ? 1 : (get_next_line(fd, &buff) > 0)))
	{
		if (*last_buffer == NULL && !ft_strempty(buff))
			ft_putendl(buff);
		if ((check = step_comment(fd, &buff, last_buffer)))
		{
			if ((check = parse_link(buff, link)))
			{
				free(buff);
				*last_buffer = NULL;
			}
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
	}
	return (check);
}
