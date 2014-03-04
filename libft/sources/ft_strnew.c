/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 12:49:33 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:07:48 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = malloc(sizeof(char *) * (size + 1));
	if (str)
	{
		size++;
		while (size)
		{
			size--;
			str[size] = 0;
		}
		return (str);
	}
	else
		return (NULL);
}
