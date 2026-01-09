/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 02:32:43 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/08 15:59:55 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynvect.h"
#include "rt_structures.h"
#include "scene/intersect_shapes.h"
#include "scene/mlx_window.h"
#include "utils/rt_utils.h"
#include <math.h>
#include <stdio.h>

// static uint32_t	shading(t_hit *hit)
// {
// 	return (0);
// }

static bool	hit_object(t_ray ray, t_object *obj, t_hit *hit)
{
	if (obj->type == T_SPHERE)
		return (hit_sphere(ray, obj->shape.sphere, hit));
	if (obj->type == T_PLANE)
		return (hit_plane(ray, obj->shape.plane, hit));
	if (obj->type == T_CYLINDER)
		return (hit_cylinder(ray, obj->shape.cylinder, hit));
	return (false);
}

static bool	intersect_scene_objects(t_dynvec *objs, t_ray ray, t_hit *hit)
{
	size_t	i;
	bool	has_hit;
	t_hit	tmp_hit;

	i = 0;
	has_hit = false;
	while (i < objs->len)
	{
		if (hit_object(ray, &((t_object *)objs->array)[i], &tmp_hit))
		{
			if (!has_hit || tmp_hit.t < hit->t)
				*hit = tmp_hit;
			has_hit = true;
		}
		i++;
	}
	return (has_hit);
}

static t_ray	generate_ray(t_camera camera, uint32_t x, uint32_t y)
{
	t_ray	ray;
	double	cam_x;
	double	cam_y;
	double	aspect_ratio;
	double	scale;

	scale = tan((camera.fov / 2) * (M_PI / 180.0));
	aspect_ratio = (double)WIDTH / HEIGHT;
	cam_x = (2 * ((x + 0.5) / WIDTH) - 1) * scale * aspect_ratio;
	cam_y = (1 - 2 * ((y + 0.5) / HEIGHT)) * scale;
	ray.origin = camera.origin;
	ray.direction = tuple_mul_scalar(camera.right, cam_x);
	ray.direction = adding_tuple(ray.direction, tuple_mul_scalar(camera.up,
				cam_y));
	ray.direction = adding_tuple(ray.direction, camera.forward);
	ray.direction = vec3_normalize(ray.direction);
	return (ray);
}

void	raytrace(t_camera camera, t_dynvec *objs, t_mlx_img *img)
{
	uint32_t	x;
	uint32_t	y;
	t_hit		hit;
	uint32_t	color;
	t_ray		ray;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = generate_ray(camera, x, y);
			if (intersect_scene_objects(objs, ray, &hit))
			{
				// color = shading(&hit);
				color = hit.color.rgb;
			}
			else
				color = graduate_background(ray.direction.y);
			my_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}
