/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 02:32:43 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/30 13:18:32 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include "scene/mlx_window.h"
#include "scene/render.h"
#include <math.h>

static uint32_t	graduate_background(double y)
{
	double	a;
	double	r;
	double	g;
	double	b;

	a = 0.5 * y + 1;
	if (a < 0)
		a = 0;
	if (a > 1)
		a = 1;
	r = (1 - a) * 255.0 + a * 127.995;
	g = (1 - a) * 255.0 + a * 179.1993;
	b = (1 - a) * 255.0 + a * 255.999;
	return (get_color(r, g, b));
}

// static uint32_t	shading(t_hit *hit)
// {
// 	return (0);
// }

static bool	intersect_scene_objects(t_obj **objs, t_ray ray, t_hit *hit)
{
	uint32_t	i;
	bool		has_hit;
	t_hit		tmp_hit;

	i = 0;
	has_hit = false;
	while (objs[i])
	{
		if (hit_object(ray, objs[i], hit))
		{
			if (!has_hit || hit->t > tmp_hit.t)
				hit->t = tmp_hit.t;
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

	scale = tan((FOV * 0.5) * (M_PI / 180.0));
	aspect_ratio = (double)WIDTH / HEIGHT;
	cam_x = (2 * ((x + 0.5) / WIDTH) - 1) * scale;
	cam_y = (1 - 2 * ((y + 0.5) / HEIGHT)) * (scale / aspect_ratio);
	ray.origin = camera.origin;
	ray.direction = tuple_mul_scalar(camera.right, cam_x);
	ray.direction = adding_tuple(ray.direction, tuple_mul_scalar(camera.up,
				cam_y));
	ray.direction = adding_tuple(ray.direction, camera.forward);
	ray.direction = vec3_normalize(ray.direction);
	return (ray);
}

void	raytrace(t_camera camera, t_obj **objs, t_mlx_img *img)
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
