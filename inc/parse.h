/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:14:25 by npineau           #+#    #+#             */
/*   Updated: 2014/02/13 14:17:19 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

void	lem_error(t_map *map, char *line);
void	lem_start(t_map *map, char *line);
void	lem_end(t_map *map, char *line);
void	lem_comment(t_map *map, char *line);
void	lem_link(t_map *map, char *line);
void	lem_ant(t_map *map, char *line);
void	lem_room(t_map *map, char *line);

#endif
