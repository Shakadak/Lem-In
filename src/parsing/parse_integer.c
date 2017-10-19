/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 15:28:13 by npineau           #+#    #+#             */
/*   Updated: 2017/10/19 15:54:13 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"

int	skip_char(char c, char* buff, char **leftover)
{
	if (buff == NULL)
	{
		return (0);
	}
	else if (buff[0] == c)
	{
		*leftover = ft_strdup(buff + 1);
		return (1);
	}
	else
	{
		return (0);
	}
}

int	parse_natural;
