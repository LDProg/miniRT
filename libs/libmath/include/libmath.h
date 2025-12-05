/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:40:16 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/05 06:43:54 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

# include "libmath_structures.h"
# include <stdbool.h>

// Matrice Creation
t_mat4	mat4_identity(void);
t_mat4	mat4_zero(void);

// Matrice Operations
t_mat4	mat4_mul(t_mat4 a, t_mat4 b);
t_vec3	mat4_mul_vec3(t_mat4 m, t_vec3 v);
t_mat4	mat4_transpose(t_mat4 m);

// Matrice Transformations
t_mat4	mat4_translation(double x, double y, double z);
t_mat4	mat4_scale(double x, double y, double z);
t_mat4	mat4_rotation_x(double angle);
t_mat4	mat4_rotation_y(double angle);
t_mat4	mat4_rotation_z(double angle);

// Vector Creation
t_tuple	create_tuple(double x, double y, double z, double w);
t_tuple	create_point(double x, double y, double z);
t_tuple	create_vector(double x, double y, double z);

// Vector Comparaisons
bool	is_point(t_tuple t);
bool	is_vector(t_tuple t);
bool	is_vector_null(t_tuple v);
bool	is_floats_equals(double x, double y);
bool	is_tuples_equals(t_tuple t1, t_tuple t2);

// Tuple Operations
t_tuple	adding_tuple(t_tuple t1, t_tuple t2);
t_tuple	substract_tuple(t_tuple t1, t_tuple t2);
t_tuple	tuple_mul_scalar(t_tuple t, double s);
t_tuple	tuple_div_scalar(t_tuple t, double s);
t_tuple	tuple_mul_comp(t_tuple t1, t_tuple t2);

// Vector operations
double	vector_magnitude(t_tuple v);
t_tuple	vector_normalize(t_tuple v);
double	vector_dot(t_tuple v1, t_tuple v2);
t_tuple	vector_cross(t_tuple v1, t_tuple v2);

#endif
