/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 13:36:04 by mde-jesu          #+#    #+#             */
/*   Updated: 2017/10/21 18:12:02 by nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft.h"

typedef enum		e_room_type
{
	NORMAL,
	START,
	END
}					t_room_type;

typedef struct		s_coor
{
	int				x;
	int				y;
}					t_coor;

typedef struct		s_room
{
	t_room_type		type;
	t_coor			coord;
	char			*name;
	t_lst			*conn;
	int				weight;
}					t_room;

typedef struct		s_link
{
	char			*fst;
	char			*sec;
}					t_link;

#endif
