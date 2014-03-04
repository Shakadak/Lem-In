/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:12:47 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:08:29 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *dest, const char *mod)
{
	int	length;
	int	i;

	i = 0;
	length = ft_strlen(mod);
	if (length > 0)
	{
		while (dest[i] != 0)
		{
			if (dest[i] == mod[0])
			{
				if (!(ft_strncmp(&dest[i], mod, length)))
					return ((char *) &dest[i]);
			}
			i++;
		}
		return (NULL);
	}
	else
		return ((char *) dest);
}
