/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 16:54:50 by npineau           #+#    #+#             */
/*   Updated: 2014/02/13 13:17:59 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef enum		e_type
{
					BASIC,
					START,
					END
}					t_type;

typedef struct		s_lpipe
{
	struct s_lroom	*name;
	struct s_lpipe	*next;
}					t_lpipe;

typedef struct		s_lroom
{
	t_type			type;
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

#endif
