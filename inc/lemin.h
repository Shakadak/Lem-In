/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:41:02 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/10/24 15:32:00 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define SRT_ERR 1
# define END_ERR 2
# define LNK_ERR 4
# define OTH_ERR 8

void	init_graph(t_room *rooms, size_t roomnbr, t_rb links, unsigned int *error);
void	go_link(t_room *r1, t_room *r2);
void	print_graph(t_room *rooms, int rnb);
//t_room	*find_start_and_error(t_room *rooms, int roomnbr, unsigned int *error);
void	what_error(unsigned int error);
int		get_anthill(size_t *ants, t_room **rooms, size_t *rooms_n, t_rb *links);

#endif
