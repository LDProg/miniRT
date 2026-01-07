/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:57:33 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/07 13:58:12 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "rt_structures.h"
#include "utils/rt_utils.h"
#include "minirt.h"

// bool	hit_plane(t_ray ray, t_plane *pl, t_hit *hit)
bool	hit_plane(t_ray *ray, t_obj *pl, t_obj *d_light, t_obj *a_light)
{
	double	denom;
	t_vec3	oc;
	double	t;

	denom = vec3_dot(pl->normal, ray->direction);
	if (fabs(denom) < EPSILON)
		return (false);
	oc = substract_tuple(pl->center, ray->origin);
	t = vec3_dot(oc, pl->normal) / denom;
	if (t < EPSILON)
		return (false);
	ray->hit.t = t;
	ray->hit.point = adding_tuple(ray->origin, tuple_mul_scalar(ray->direction, t));
	ray->hit.normal = pl->normal;
	handle_ray(ray, pl, d_light, a_light);
	// ray->color.rgb = normal_color(hit->point, pl->center);
	return (true);
}
