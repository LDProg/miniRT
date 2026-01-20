/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:57:35 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/14 13:35:37 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include "utils/rt_utils.h"

bool	hit_sphere(t_ray ray, t_sphere sp, t_hit *hit)
{
	double	t;
	t_vec3	oc;
	double	a;
	double	b;
	double	c;

	oc = substract_tuple(ray.origin, sp.center);
	a = vec3_dot(ray.direction, ray.direction);
	b = 2 * vec3_dot(ray.direction, oc);
	c = vec3_dot(oc, oc) - sp.radius * sp.radius;
	if (solve_quadatric(a, b, c, &t))
	{
		hit->t = t;
		hit->point = adding_tuple(ray.origin, tuple_mul_scalar(ray.direction,
					t));
		hit->normal = tuple_div_scalar(substract_tuple(hit->point, sp.center),
				sp.radius);
		hit->shape_color = sp.color;
		return (true);
	}
	return (false);
}
