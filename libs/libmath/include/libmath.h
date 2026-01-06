/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:40:16 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 08:09:04 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

# include "libmath_structures.h"
# include <stdbool.h>

// Debug
void	mat4_print(t_mat4 m, char *name);
void	mat4_print_basis(t_mat4 m, char *name);
void	vec3_print(t_vec3 v, const char *name);

// Matrice Creation
t_mat4	mat4_identity(void);
t_mat4	mat4_zero(void);
t_mat4	mat4_new(t_tuple x, t_tuple y, t_tuple z, t_tuple t);

// Matrice Operations
t_tuple	mat4_mul_point(t_mat4 m, t_tuple p);
t_tuple	mat4_mul_vector(t_mat4 m, t_tuple v);
t_mat4	mat4_mul(t_mat4 a, t_mat4 b);
t_mat4	mat4_transpose(t_mat4 m);
double	mat3_det(t_mat3 m);

// Matrice Transformations
t_mat4	mat4_translation(double x, double y, double z);
t_mat4	mat4_scale(double x, double y, double z);
t_mat4	mat4_rotation_x(double angle);
t_mat4	mat4_rotation_y(double angle);
t_mat4	mat4_rotation_z(double angle);

// Vector Creation
t_tuple	tuple_new(double x, double y, double z, double w);
t_tuple	point3_new(double x, double y, double z);
t_tuple	vec3_new(double x, double y, double z);

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
double	vec3_magnitude(t_vec3 v);
t_vec3	vec3_normalize(t_vec3 v);
double	vec3_dot(t_vec3 v, t_vec3 w);
t_vec3	vec3_cross(t_vec3 v, t_vec3 w);
t_vec3	vec3_negate(t_vec3 v);

#endif
