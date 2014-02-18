/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 16:01:03 by npineau           #+#    #+#             */
/*   Updated: 2014/02/18 15:23:25 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

static void	travel_link(t_lpipe *current, char *src);
static void	travel_room(t_lroom *current, int n);
static void	display_command(t_lroom *current);

void		display_map(t_map *map)
{
	if (map)
	{
		if (map->ants)
		{
			ft_putnbr(map->ants);
			ft_putchar('\n');
			if (map->map)
			{
				travel_room(map->map, 0);
				travel_room(map->map, 1);
			}
		}
	}
}

static void	travel_room(t_lroom *current, int n)
{
	if (!current)
		return ;
	travel_room(current->next, n);
	if (n)
		travel_link(current->link, current->name);
	else
	{
		display_command(current);
		ft_putstr(current->name);
		ft_putchar(' ');
		ft_putnbr(current->coo.x);
		ft_putchar(' ');
		ft_putnbr(current->coo.y);
		ft_putchar('\n');
	}
}

static void	travel_link(t_lpipe *current, char *src)
{
	if (src && current)
	{
		if (current->name && !(current->duplicate))
		{
			ft_putstr(src);
			ft_putchar('-');
			ft_putendl(current->name->name);
		}
		travel_link(current->next, src);
	}
}

static void	display_command(t_lroom *current)
{
	if (current->type == TSTART)
		ft_putendl("##start");
	else if (current->type == TEND)
		ft_putendl("##end");
}
