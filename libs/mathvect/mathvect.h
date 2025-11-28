/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathvect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:51:41 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/28 17:48:10 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHVECT_H
# define MATHVECT_H

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	int		w;
}	t_tuple;

t_tuple	add_vect_point(t_tuple vector, t_tuple point);
void	init_tuple(t_tuple *t);
t_tuple	sub_two_vect(t_tuple v1, t_tuple v2);
t_tuple	sub_point_vect(t_tuple p, t_tuple v);
t_tuple	sub_two_points(t_tuple p1, t_tuple p2);

#endif
