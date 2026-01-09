/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:57:33 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/08 15:59:43 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "rt_structures.h"
#include "utils/rt_utils.h"

bool	hit_plane(t_ray ray, t_plane pl, t_hit *hit)
{
	double	denom;
	t_vec3	oc;
	double	t;

	denom = vec3_dot(pl.normal, ray.direction);
	if (fabs(denom) < EPSILON)
		return (false);
	oc = substract_tuple(pl.center, ray.origin);
	t = vec3_dot(oc, pl.normal) / denom;
	if (t < EPSILON)
		return (false);
	hit->t = t;
	hit->point = adding_tuple(ray.origin, tuple_mul_scalar(ray.direction, t));
	hit->normal = pl.normal;
	hit->color.rgb = normal_color(hit->point, pl.center);
	return (true);
}
