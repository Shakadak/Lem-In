/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:41:02 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/11/24 14:26:06 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define SRT_ERR 1
# define END_ERR 2
# define LNK_ERR 4
# define STC_ERR 8
# define OTH_ERR 16

# include "inc/structs.h"

void	init_graph(t_room *rooms, size_t qty, t_rb links, unsigned int *err);
void	go_link(t_room *r1, t_room *r2);
void	print_graph(t_room const *rooms, size_t rnb);
t_room	*find_start_and_error(t_room *rooms, int roomnbr, unsigned int *error);
void	what_error(unsigned int error);
int		get_anthill(size_t *ants, t_rb *rooms, size_t *qty, t_rb *links);
t_room	*get_lightest_neighbor(t_room room);
void	init_weight(t_room *start, unsigned int *error);
void	recursive_weight(t_rb *queu, int weight, size_t cnt);
void	weight_from_end(t_room *end);
t_room	*find_type(
		t_room_type type,
		t_room *rooms,
		int roomnbr);
int		check_rooms(t_room *rooms, size_t qty, unsigned int *err);
void	transfer_ants(size_t ants, t_room *start);

#endif
