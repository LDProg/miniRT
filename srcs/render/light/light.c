/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 04:43:12 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/10 06:35:08 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include "utils/rt_utils.h"

static double	get_angle(t_vec3 l, t_vec3 n)
{
	double	angle;

	angle = vec3_dot(l, n);
	if (angle < 0)
		return (0);
	return (angle);
}

// Ambient color = intensity *src_color * obj_color

// static t_color	ambient_lt(t_hit hit, t_color a_light)
// {
// 	t_color	color;

// 	color = compute_color(a_light.ratio, a_light, hit.shape_color);
// 	return (color);
// }

// Diffuse color = ratio * max(l.n, 0) * src_color * obj_color

static t_color	diffuse_lt(t_hit hit, t_light d_light)
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
	vec_light = vec3_normalize(substract_tuple(d_light.position, hit.point));
	angle = get_angle(vec_light, hit.normal);
	color = compute_color(d_light.color.ratio * angle, d_light.color,
			hit.shape_color);
	return (color);
}

uint32_t	compute_hit_color(t_hit hit, t_color a_light, t_light d_light)
{
	t_color	diffuse;
	t_color	ambient;

	diffuse = diffuse_lt(hit, d_light);
	ambient = compute_color(a_light.ratio, a_light, hit.shape_color);
	return (add_colors(ambient, diffuse));
}
