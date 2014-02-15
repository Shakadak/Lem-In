/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 16:54:50 by npineau           #+#    #+#             */
/*   Updated: 2014/02/15 14:02:11 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct		s_coo
{
	int				x;
	int				y;
}					t_coo;

typedef enum		e_type
{
					TANT,
					TBASIC,
					TSTART,
					TEND,
					TLINK,
					TSTOP
}					t_type;

typedef struct		s_lpipe
{
	struct s_lroom	*name;
	struct s_lpipe	*next;
}					t_lpipe;

typedef struct		s_lroom
{
	t_type			type;
	t_coo			coo;
	char			*name;
	t_lpipe			*link;
	struct s_lroom	*next;
}					t_lroom;

typedef enum		e_token
{
					ERROR,
					START,
					END,
					COMMENT,
					LINK,
					ANT,
					ROOM
}					t_token;

typedef struct		s_map
{
	int				ants;
	t_lroom			start;
	t_lroom			end;
	t_lroom			map;
	t_type			next;
}					t_map;

typedef void	(*t_func)(t_map *, char *);

char	**ft_strtrimsplit(char *line, char c);
void	get_map(t_map *map);
int		check_line(char *line);
void	get(int token, t_map *map, char *line);
char	*get_token(char **src);

#endif
