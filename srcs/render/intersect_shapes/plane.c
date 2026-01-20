/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:57:33 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/20 18:00:38 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include <math.h>

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
	hit->t = t;
	hit->point = adding_tuple(ray.origin, tuple_mul_scalar(ray.direction, t));
	hit->normal = pl.normal;
	hit->shape_color = pl.color;
	return (true);
}
