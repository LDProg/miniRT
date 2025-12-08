/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathvect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:51:41 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/08 13:11:01 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHVECT_H
# define MATHVECT_H

# include "libmath_structures.h"

// typedef struct	s_tuple
// {
// 	float		x;
// 	float		y;
// 	float		z;
// 	int			w;
// }				t_tuple;

/*----------VECTOR----------*/

t_tuple		add_vect_point(t_tuple vector, t_tuple point);
void		init_tuple(t_tuple *t);
t_tuple		sub_two_vect(t_tuple v1, t_tuple v2);
t_tuple		sub_point_vect(t_tuple p, t_tuple v);
t_tuple		sub_two_points(t_tuple p1, t_tuple p2);
t_tuple		inv_tup(t_tuple v);
t_tuple		scalar_mult(t_tuple v, double	factor);
t_tuple		 scalar_div(t_tuple v, double factor);
double		vect_mag(t_tuple v);
t_tuple		normalize_vect(t_tuple v);
double		dot_product(t_tuple v1, t_tuple v2);
t_tuple 	cross_product(t_tuple v1, t_tuple v2);
t_point3	position(t_point3 ray_origin, t_vec3 ray_dir, double t);

/*----------MATRIX----------*/

t_tuple		translate_matrix(t_tuple t, double trx, double try, double trz);
t_tuple		all_rotate_matrix(t_tuple t, double angle_x, double angle_y, double angle_z);
t_tuple		rotate_x(t_tuple t, double alpha);
t_tuple		rotate_y(t_tuple t, double alpha);
t_tuple		rotate_z(t_tuple t, double alpha);

#endif
