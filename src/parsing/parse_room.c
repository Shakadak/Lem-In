/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:34:29 by npineau           #+#    #+#             */
/*   Updated: 2017/10/19 15:54:26 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/structs.h"

static int	is_invalid_fst(char c)
{
	return (c == 'L' || c == '#' || ft_isspace(c));
}


static int	parse_lexed_name(char *buff, char **name, char **leftover)
{
	t_pair	pair;

	pair = strbreak(ft_isspace, line);
	*name = pair.fst;
	*leftover = pair.snd;
	pair = strspan(ft_isspace, *leftover);
	free(pair.fst);
	*leftover = pair.snd;
	return (1);
}

static int parse_lexed_integer(char *buff, int *c, char **leftover)
{
	t_pair	pair;
	int		negatif;
	int		check;
	char	*num;
	char	*tmp;

	negatif = !ft_strempty(buff) && ft_strnequ(buff, "-", 1);
	pair = strspan(ft_isdigit, buff + 1);
	check = !ft_strempty(pair.fst);
	num = pair.fst;
	tmp = pair.snd;
	pair = strspan(ft_isspace, tmp);
	free(tmp);
	if (ft_isempty(pair.fst) && !ft_isempty(pair.snd))
	{
		check = 0;
		free(num);
		free(pair.fst);
		free(pair.snd);
	}
	else
	{
}

int	parse_room(char *line, t_room *room)
{
	int		check;
	t_pair	pair;
	char	*name;
	char	*tmp;

	check = !ft_strempty(line) && !is_invalid_fst(line[0]);
	if (check)
	{
		name = pair.fst;
		tmp = pair.snd;
		pair = strspan(ft_isspace, tmp);
		free(tmp);
		free(pair.fst);
}
