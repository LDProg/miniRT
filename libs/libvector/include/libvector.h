/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:40:16 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/02 06:51:43 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTOR_H
# define LIBVECTOR_H

# include "vector_structures.h"
# include <stdbool.h>

/*Creation*/
t_tuple	create_tuple(double x, double y, double z, double w);
t_tuple	create_point(double x, double y, double z);
t_tuple	create_vector(double x, double y, double z);

/*Comparaisons*/
bool	is_point(t_tuple t);
bool	is_vector(t_tuple t);
bool	is_vector_null(t_tuple v);
bool	is_floats_equals(double x, double y);
bool	is_tuples_equals(t_tuple t1, t_tuple t2);

/*Operations*/
t_tuple	adding_tuple(t_tuple t1, t_tuple t2);
t_tuple	substract_tuple(t_tuple t1, t_tuple t2);
t_tuple	tuple_mul_scalar(t_tuple t, double s);
t_tuple	tuple_div_scalar(t_tuple t, double s);
t_tuple	tuple_mul_comp(t_tuple t1, t_tuple t2);

/*Vector operations*/
double	vector_magnitude(t_tuple v);
t_tuple	vector_normalize(t_tuple v);
double	vector_dot(t_tuple v1, t_tuple v2);
t_tuple	vector_cross(t_tuple v1, t_tuple v2);

#endif
