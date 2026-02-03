/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:04:44 by ludebion          #+#    #+#             */
/*   Updated: 2026/02/01 09:36:37 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/intersect_shapes.h"
#include "utils/rt_utils.h"
#include <math.h>

static bool	hit_cone_cap(t_ray ray, t_cone co, t_hit *hit)
{
	t_plane	cap;
	t_hit	tmp;
	double	radius;

	hit->t = INFINITY;
	radius = co.height * tan(co.angle);
	cap.center = adding_tuple(co.center, tuple_mul_scalar(co.axis, co.height));
	cap.normal = co.axis;
	cap.color = co.color;
	cap.radius = radius;
	if (hit_disk(ray, cap, &tmp) && tmp.t < hit->t)
		*hit = tmp;
	return (hit->t < INFINITY);
}

static bool	hit_cone_side_calc(t_ray ray, t_cone co, t_vec3 oc, double *t)
{
	double	a;
	double	b;
	double	c;
	double	m;

	a = vec3_dot(ray.direction, co.axis);
	a = a * a - cos(co.angle) * cos(co.angle) * vec3_dot(ray.direction,
			ray.direction);
	b = 2 * (vec3_dot(ray.direction, co.axis) * vec3_dot(oc, co.axis)
			- cos(co.angle) * cos(co.angle) * vec3_dot(ray.direction, oc));
	c = vec3_dot(oc, co.axis) * vec3_dot(oc, co.axis) - cos(co.angle)
		* cos(co.angle) * vec3_dot(oc, oc);
	if (!solve_quadatric(a, b, c, t) || *t < __LDBL_EPSILON__)
		return (false);
	m = vec3_dot(ray.direction, co.axis) * *t + vec3_dot(oc, co.axis);
	if (m < 0 || m > co.height)
		return (false);
	return (true);
}

static bool	hit_cone_side(t_ray ray, t_cone co, t_hit *hit)
{
	t_vec3	oc;
	double	t;
	double	m;

	oc = substract_tuple(ray.origin, co.center);
	if (!hit_cone_side_calc(ray, co, oc, &t))
		return (false);
	hit->t = t;
	hit->point = adding_tuple(ray.origin, tuple_mul_scalar(ray.direction, t));
	oc = substract_tuple(hit->point, co.center);
	m = vec3_dot(oc, co.axis);
	oc = substract_tuple(oc, tuple_mul_scalar(co.axis, m * (1 + tan(co.angle)
					* tan(co.angle))));
	hit->normal = vec3_normalize(oc);
	if (vec3_dot(ray.direction, hit->normal) > 0)
		hit->normal = vec3_negate(hit->normal);
	hit->shape_color = co.color;
	return (true);
}

bool	hit_cone(t_ray ray, t_cone co, t_hit *hit)
{
	t_hit	side;
	t_hit	cap;
	bool	side_hit;
	bool	cap_hit;

	side_hit = hit_cone_side(ray, co, &side);
	cap_hit = hit_cone_cap(ray, co, &cap);
	if (!side_hit && !cap_hit)
		return (false);
	if (side_hit && (!cap_hit || side.t < cap.t))
		*hit = side;
	else
		*hit = cap;
	return (true);
}
