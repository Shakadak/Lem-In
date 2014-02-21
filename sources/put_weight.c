/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_weight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 16:02:44 by npineau           #+#    #+#             */
/*   Updated: 2014/02/21 18:06:46 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "lem-in.h"

void	put_weight(t_lroom *current, int	weight)
{
	t_lpipe		*tmp;

	if (!current)
		return ;
	if (current->weight == -1)
		current->weight = weight;
	else
	{
		if (current->weight < weight)
			return ;
		if (current->weight > weight)
			current->weight = weight;
	}
	tmp = current->link;
	while (tmp)
	{
		put_weight(tmp->name, weight + 1);
		tmp = tmp->next;
	}
}
