/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 04:43:12 by ludebion          #+#    #+#             */
/*   Updated: 2026/02/03 03:27:41 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/intersect_shapes.h"
#include "utils/rt_utils.h"
#include <math.h>
#include <stdio.h>

// Diffuse color = ratio * max(l.n, 0) * src_color * obj_color

static t_vec3	reflect(t_vec3 l, t_vec3 n)
{
	return (substract_tuple(l, tuple_mul_scalar(n, 2.0 * vec3_dot(l, n))));
}

static t_color	specular_lt(t_hit hit, t_light d_light, t_vec3 vec_light,
		t_vec3 vec_view)
{
	t_vec3	r;
	double	spec;

	if (vec3_dot(vec_light, hit.normal) <= 0)
		return ((t_color){0, 0, 0, 0, 0});
	r = reflect(vec3_negate(vec_light), hit.normal);
	spec = vec3_dot(r, vec_view);
	if (spec <= 0)
		return ((t_color){0, 0, 0, 0, 0});
	spec = pow(spec, 32);
	return (compute_color(d_light.color.ratio * spec, d_light.color,
			(t_color){.r = 255, .g = 255, .b = 255}));
}

static t_color	diffuse_lt(t_hit hit, t_light d_light, t_vec3 vec_light)
{
	t_color	color;
	double	angle;

	angle = vec3_dot(vec_light, hit.normal);
	if (angle < 0)
		angle = 0;
	color = compute_color(d_light.color.ratio * angle, d_light.color,
			hit.shape_color);
	return (color);
}

static t_color	apply_light(t_scene scene, t_hit hit, t_color result,
		t_light *light)
{
	t_ray	ray;
	t_hit	tmp;
	double	dist;
	t_vec3	view;
	t_color	tmp_color;

	ray.origin = adding_tuple(hit.point, tuple_mul_scalar(hit.normal,
				__FLT_EPSILON__));
	ray.direction = vec3_normalize(substract_tuple(light->position,
				ray.origin));
	dist = vec3_distance(light->position, hit.point);
	view = vec3_normalize(substract_tuple(scene.camera.origin, hit.point));
	if (!intersect_scene_objects(scene.objs, ray, &tmp) || tmp.t > dist)
	{
		tmp_color = diffuse_lt(hit, *light, ray.direction);
		result = add_color_raw(result, tmp_color);
		tmp_color = specular_lt(hit, *light, ray.direction, view);
		result = add_color_raw(result, tmp_color);
	}
	return (result);
}

uint32_t	compute_hit_color(t_scene scene, t_hit hit)
{
	t_color	result;
	size_t	i;
	t_light	*lights;

	result = compute_color(scene.ambient.ratio, scene.ambient, hit.shape_color);
	lights = (t_light *)scene.lights->array;
	i = 0;
	while (i < scene.lights->len)
	{
		result = apply_light(scene, hit, result, &lights[i]);
		i++;
	}
	return (add_colors(result, (t_color){0, 0, 0, 0, 0}));
}
