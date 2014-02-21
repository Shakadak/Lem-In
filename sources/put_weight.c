/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_weight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 16:02:44 by npineau           #+#    #+#             */
/*   Updated: 2014/02/21 17:22:18 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	put_weight(t_lroom *current, int	weight)
{
	t_lpipe		*tmp;

	if (!current)
		return ;
	if (current->weight != 0 && current->weight < weight)
		return ;
	tmp = current->link;
	current->weight = weight;
	while (tmp)
	{
		put_weight(tmp->name, weight + 1);
		tmp = tmp->next;
	}
}
