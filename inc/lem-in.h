/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:41:02 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/10/18 16:09:19 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

int		init_graph(t_room *rooms, int roomnbr, t_rb links);
void	go_link(t_room *r1, t_room *r2);
void	print_graph(t_room *rooms, int rnb);

#endif
