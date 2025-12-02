/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:15:22 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/02 04:23:08 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"
#include <math.h>

double	vector_magnitude(t_tuple v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

double	vector_distance(t_tuple v1, t_tuple v2)
{
	return (vector_magnitude(substract_tuple(v1, v2)));
}

t_tuple	vector_normalize(t_tuple v)
{
	return (tuple_div_scalar(v, vector_magnitude(v)));
}

double	vector_dot(t_tuple v1, t_tuple v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_tuple	vector_cross(t_tuple v1, t_tuple v2)
{
	return (create_vector((v1.y * v2.z) - (v1.z * v2.y), (v1.z * v2.x) - (v1.x
				* v2.z), (v1.x * v2.y) - (v1.y * v2.x)));
}
