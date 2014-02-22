/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_weight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 16:02:44 by npineau           #+#    #+#             */
/*   Updated: 2014/02/22 14:10:17 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (current->type == TSTART)
		return ;
	tmp = current->link;
	while (tmp)
	{
		put_weight(tmp->name, weight + 1);
		tmp = tmp->next;
	}
}
