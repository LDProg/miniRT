/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:15:22 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/19 03:02:12 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include <math.h>

double	vector_magnitude(t_vec3 v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

double	vector_distance(t_tuple v, t_tuple w)
{
	return (vector_magnitude(substract_tuple(v, w)));
}

t_vec3	vector_normalize(t_vec3 v)
{
	return (tuple_div_scalar(v, vector_magnitude(v)));
}

double	vector_dot(t_vec3 v, t_vec3 w)
{
	return ((v.x * w.x) + (v.y * w.y) + (v.z * w.z));
}

t_tuple	vector_cross(t_vec3 v, t_vec3 w)
{
	return (create_vector((v.y * w.z) - (v.z * w.y), (v.z * w.x) - (v.x * w.z),
			(v.x * w.y) - (v.y * w.x)));
}
