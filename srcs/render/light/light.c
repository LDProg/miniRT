/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 04:43:12 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/20 14:08:48 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include "utils/rt_utils.h"
#include "scene/intersect_shapes.h"
#include "libmath.h"
#include <stdio.h>



// Diffuse color = ratio * max(l.n, 0) * src_color * obj_color

static t_color	diffuse_lt(t_hit hit, t_light d_light, t_vec3 vec_light)
{
	// t_vec3	vec_light;
	t_color	color;
	double	angle;

	// vec_light = vec3_normalize(substract_tuple(d_light.position, hit.point));
	angle = get_angle(vec_light, hit.normal);
	color = compute_color(d_light.color.ratio * angle, d_light.color,
			hit.shape_color);
	return (color);
}

uint32_t	compute_hit_color(t_hit hit, t_color a_light, t_light d_light, t_scene scene)
{
	t_color	diffuse;
	t_color	ambient;
	t_ray	ray_light;
	t_hit	hit_light;

	(void)scene;
	ray_light.direction = vec3_normalize(substract_tuple(d_light.position, hit.point));
	ray_light.origin = hit.point;
	if (!intersect_scene_objects(scene.objs, ray_light, &hit_light))
		diffuse = diffuse_lt(hit, d_light, ray_light.direction);
	else
		extract_rgb(0, &diffuse);
	ambient = compute_color(a_light.ratio, a_light, hit.shape_color);
	return (add_colors(ambient, diffuse));
}
