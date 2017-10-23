/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 13:48:37 by npineau           #+#    #+#             */
/*   Updated: 2017/10/23 15:05:34 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "inc/structs.h"

typedef char*	t_string;

typedef enum	e_parse_step
{
	ANTS,
	ROOMS,
	LINKS,
}				t_parse_step;

int				spaces(t_string buff, t_string *leftover);
int				spaces1(t_string buff, t_string *leftover);
int				parse_nat(t_string in, t_string *out, int *nat);
int				parse_int(t_string in, t_string *out, int *integer);
int				parse_name(t_string in, t_string *out, t_string *name);
int				parse_lexed_name(t_string in, t_string *out, t_string *name);
int				parse_ants(const char *line, size_t *ret);
int				parse_command(char *line, t_room_type *type);
int				parse_comment(char *line);
int				parse_link(t_string buff, t_link *link);
int				parse_room(char *line, t_room *room);

int				step_ants(int fd, size_t *ants);
int				step_links(int fd, t_rb *links, t_string *last_buffer);
int				step_rooms(int fd, t_rb *rooms, t_string *last_buffer);
#endif
