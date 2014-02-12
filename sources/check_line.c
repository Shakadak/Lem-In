/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:15:36 by npineau           #+#    #+#             */
/*   Updated: 2014/02/12 16:41:21 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	check_line(char	*line)
{
	if (*line = '\0')
		return (0);
	if (line[1] == '#')
	{
		if (line[2] == '#')
		{
			if (ft_strequ(&line[3], "start"))
					return (START);
			if (ft_strequ(&line[3], "end"))
					return (END);
		}
		return (COMMENT);
	}
	if (ft_strchr(line, '-'))
		return (LINK);
	if (full_digit(ft_strtrim(line)))
		return (ANT);
	if (count_space(ft_strtrim(line)) == 2)
		return (ROOM);
	return (ERROR);
}
