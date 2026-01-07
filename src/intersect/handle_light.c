/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:03:38 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/07 15:15:03 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include "structures.h"
#include "minirt.h"

double	get_angle(t_vec3 l, t_vec3 n)
{
	double	angle;

	angle = dot_product(l, n);
	if (angle < 0)
		return (0);
	return (angle);
}

/*
Ambient color = intensity *src_color * obj_color
*/

t_color	ambient_lt(t_obj *obj, t_obj *a_light)
{
	t_color	color;

	color = compute_color(a_light->lt_ratio, a_light->color, obj->color);
	return (color);
}

/*
Diffuse color = ratio * max(l.n, 0) * src_color * obj_color
*/

t_color	diffuse_lt(t_ray *ray, t_obj *obj, t_obj *d_light)
{
	t_vec3	vec_light;
	t_color	color;
	double	angle;

	// if (obj->type == SP)
	// {
	// 	normal = sub_two_points(ray->pos_inter, obj->pos);
	// 	normal = normalize_vect(normal);
	// }
	// if (obj->type == PL)
	// 	normal = obj->norm_v;
	vec_light = sub_two_points(d_light->pos, ray->hit.point);
	vec_light = normalize_vect(vec_light);
	angle = get_angle(vec_light, ray->hit.normal);
	color = compute_color(d_light->lt_ratio * angle, d_light->color,
			obj->color);
	return (color);
}

void	handle_ray(t_ray *ray, t_obj *obj, t_obj *d_light, t_obj *a_light)
{
	t_color	diffuse;
	t_color	ambient;

	// ray->t = t;
	ray->hit.point = scalar_mult(ray->direction, ray->hit.t);
	ray->hit.point = add_vect_point(ray->hit.point, ray->origin);
	diffuse = diffuse_lt(ray, obj, d_light);
	ambient = ambient_lt(obj, a_light);
	ray->hit.color = add_colors(ambient, diffuse);
}
