/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 11:49:31 by npineau           #+#    #+#             */
/*   Updated: 2014/02/12 12:28:17 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_token(char **src)
{
	char	*new;
	char	*tmp;

	while (**src && ft_isspace(**src))
		(*src)++;
	tmp = *src;
	while (*tmp && !ft_isspace(*tmp))
		tmp++;
	new = ft_strsub(*src, 0, tmp - *src);
	return (new);
}
