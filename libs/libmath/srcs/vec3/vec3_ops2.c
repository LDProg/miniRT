/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_ops2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 08:08:15 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/23 16:14:41 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include <math.h>
#include <stdio.h>

t_vec3	vec3_negate(t_vec3 v)
{
	t_vec3	res;

	res.x = -v.x;
	res.y = -v.y;
	res.z = -v.z;
	res.w = v.w;
	return (res);
}

double	vec3_magnitude(t_vec3 v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

double	vec3_distance(t_tuple v, t_tuple w)
{
	return (vec3_magnitude(substract_tuple(v, w)));
}

t_vec3	vec3_normalize(t_vec3 v)
{
	return (tuple_div_scalar(v, vec3_magnitude(v)));
}

bool	is_normalized_vec(t_vec3 v)
{
	double	length;

	if (v.x < -1.0 || v.x > 1.0 || v.y < -1.0 || v.y > 1.0 || v.z < -1.0
		|| v.z > 1.0)
		return (false);
	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (fabs(length - 1.0) < 0.001);
}
