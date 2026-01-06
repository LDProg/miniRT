/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:57:35 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 11:20:27 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include "utils/rt_utils.h"

bool	hit_sphere(t_ray ray, t_sphere *sp, t_hit *hit)
{
	double	t0;
	t_vec3	oc;
	double	a;
	double	b;
	double	c;

	oc = substract_tuple(ray.origin, sp->center);
	a = vec3_dot(ray.direction, ray.direction);
	b = 2 * vec3_dot(ray.direction, oc);
	c = vec3_dot(oc, oc) - sp->radius * sp->radius;
	if (solve_quadatric(a, b, c, &t0))
	{
		hit->t = t0;
		hit->point = adding_tuple(ray.origin, tuple_mul_scalar(ray.direction,
					t0));
		hit->normal = tuple_div_scalar(substract_tuple(hit->point, sp->center),
				sp->radius);
		hit->color.rgb = normal_color(hit->point, sp->center);
		// hit->color = sp->color;
		return (true);
	}
	return (false);
}
