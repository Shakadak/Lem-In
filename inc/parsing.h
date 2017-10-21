/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 13:48:37 by npineau           #+#    #+#             */
/*   Updated: 2017/10/21 15:46:49 by nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef char*	t_string;

int	spaces(t_string buff, t_string *leftover);
int	spaces1(t_string buff, t_string *leftover);
int	parse_nat(t_string in, t_string *out, int *nat);
int	parse_int(t_string in, t_string *out, int *integer);
#endif
