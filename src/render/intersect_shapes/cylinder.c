/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:57:37 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 11:43:26 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include "scene/intersect_shapes.h"
#include "utils/rt_utils.h"
#include <math.h>

static bool	hit_disk(t_ray ray, t_plane *pl, t_hit *hit, double radius)
{
	t_vec3	v_cy_center_to_p;
	double	d2;

	if (hit_plane(ray, pl, hit))
	{
		v_cy_center_to_p = substract_tuple(hit->point, pl->center);
		d2 = vec3_dot(v_cy_center_to_p, v_cy_center_to_p);
		if (d2 <= radius * radius)
			return (true);
	}
	return (false);
}

static bool	hit_caps(t_ray ray, t_cylinder *cy, t_hit *hit)
{
	t_plane	cap;
	t_hit	tmp;

	hit->t = INFINITY;
	cap.center = cy->c_top;
	cap.normal = cy->axis;
	cap.color = cy->color;
	if (hit_disk(ray, &cap, &tmp, cy->radius) && tmp.t < hit->t)
		*hit = tmp;
	cap.center = cy->c_bottom;
	cap.normal = vec3_negate(cy->axis);
	cap.color = cy->color;
	if (hit_disk(ray, &cap, &tmp, cy->radius) && tmp.t < hit->t)
		*hit = tmp;
	return (hit->t < INFINITY);
}

static bool	check_cylinder_height(t_cylinder *cy, t_hit *hit)
{
	double		m;
	t_point3	p_proj;

	m = vec3_dot(substract_tuple(hit->point, cy->c_bottom), cy->axis);
	if (m < 0 || m > cy->height)
		return (false);
	p_proj = adding_tuple(cy->c_bottom, tuple_mul_scalar(cy->axis, m));
	hit->normal = vec3_normalize(substract_tuple(hit->point, p_proj));
	hit->color.rgb = normal_color(hit->point, p_proj);
	// hit->color = cy->color;
	return (true);
}

static bool	hit_cylinder_side(t_ray ray, t_cylinder *cy, t_hit *hit)
{
	t_point3	oc;
	double		a;
	double		b;
	double		c;
	double		t0;

	oc = substract_tuple(ray.origin, cy->c_bottom);
	a = vec3_dot(ray.direction, ray.direction) - vec3_dot(ray.direction,
			cy->axis) * vec3_dot(ray.direction, cy->axis);
	b = 2 * (vec3_dot(ray.direction, oc) - vec3_dot(ray.direction, cy->axis)
			* vec3_dot(oc, cy->axis));
	c = vec3_dot(oc, oc) - vec3_dot(oc, cy->axis) * vec3_dot(oc, cy->axis)
		- cy->radius * cy->radius;
	if (solve_quadatric(a, b, c, &t0))
	{
		hit->t = t0;
		hit->point = adding_tuple(ray.origin, tuple_mul_scalar(ray.direction,
					t0));
		return (check_cylinder_height(cy, hit));
	}
	return (false);
}

bool	hit_cylinder(t_ray ray, t_cylinder *cy, t_hit *hit)
{
	t_hit	t_lat;
	t_hit	t_cap;
	bool	has_hit;

	has_hit = false;
	if (hit_cylinder_side(ray, cy, &t_lat))
	{
		*hit = t_lat;
		has_hit = true;
	}
	if (hit_caps(ray, cy, &t_cap))
	{
		if (!has_hit || t_cap.t < hit->t)
		{
			*hit = t_cap;
			has_hit = true;
		}
	}
	return (has_hit);
}
