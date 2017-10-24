/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 15:45:59 by npineau           #+#    #+#             */
/*   Updated: 2017/10/19 15:54:16 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"

int	spaces(char *buff, char **leftover)
{
	t_pair	pair;

	pair = strspan(ft_isspace, buff);
	free(pair.fst);
	*leftover = pair.snd;
	return (1);
}

int	spaces1(char *buff, char **leftover)
{
	return (ft_isspace(buff[0]) ? spaces(buff, leftover) : 0);
}
