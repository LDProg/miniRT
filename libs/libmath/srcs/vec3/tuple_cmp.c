/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:57:06 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/23 11:33:07 by gaducurt         ###   ########.fr       */
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
	return (fabs(v.x) < __LDBL_EPSILON__ && fabs(v.y) < __LDBL_EPSILON__
		&& fabs(v.z) < __LDBL_EPSILON__);
}

bool	is_floats_equals(double x, double y)
{
	return (fabs(x - y) < __LDBL_EPSILON__);
}

bool	is_tuples_equals(t_tuple t1, t_tuple t2)
{
	return (fabs(t1.x - t2.x) < __LDBL_EPSILON__ && fabs(t1.y
			- t2.y) < __LDBL_EPSILON__ && fabs(t1.z - t2.z) < __LDBL_EPSILON__
		&& t1.w == t2.w);
}
