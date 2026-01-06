/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:57:06 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/05 06:41:12 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath_structures.h"
#include <math.h>
#include <stdbool.h>

bool	is_point(t_tuple t)
{
	return (t.w == 1.0);
}

bool	is_vector(t_tuple t)
{
	return (t.w == 0.0);
}

bool	is_vector_null(t_tuple v)
{
	return (fabs(v.x) < EPSILON && fabs(v.y) < EPSILON && fabs(v.z) < EPSILON);
}

bool	is_floats_equals(double x, double y)
{
	return (fabs(x - y) < EPSILON);
}

bool	is_tuples_equals(t_tuple t1, t_tuple t2)
{
	return (fabs(t1.x - t2.x) < EPSILON && fabs(t1.y - t2.y) < EPSILON
		&& fabs(t1.z - t2.z) < EPSILON && t1.w == t2.w);
}
