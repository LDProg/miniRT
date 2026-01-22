/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 02:32:43 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/22 13:29:00 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene/intersect_shapes.h"
#include "scene/light.h"
#include "scene/mlx_window.h"
#include "utils/rt_utils.h"
#include <math.h>

static uint32_t	trace_single_ray(t_scene scene, t_ray ray)
{
	t_hit		hit;
	uint32_t	color;

	if (intersect_scene_objects(scene.objs, ray, &hit))
		color = compute_hit_color(hit, scene.ambient, scene.light, scene);
	else
		color = graduate_background(ray.direction.y);
	return (color);
}

static t_ray	generate_ray(t_camera camera, double pixel_x, double pixel_y)
{
	t_ray	ray;
	double	cam_x;
	double	cam_y;
	double	aspect_ratio;
	double	scale;

	scale = tan((camera.fov / 2) * (M_PI / 180.0));
	aspect_ratio = (double)HEIGHT / WIDTH;
	cam_x = (2 * (pixel_x / WIDTH) - 1) * scale;
	cam_y = (1 - 2 * (pixel_y / HEIGHT)) * scale * aspect_ratio;
	ray.origin = camera.origin;
	ray.direction = tuple_mul_scalar(camera.right, cam_x);
	ray.direction = adding_tuple(ray.direction, tuple_mul_scalar(camera.up,
				cam_y));
	ray.direction = adding_tuple(ray.direction, camera.forward);
	ray.direction = vec3_normalize(ray.direction);
	return (ray);
}

static uint32_t	compute_pixel_aa(t_scene scene, uint32_t x, uint32_t y)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	colors[AA_SAMPLES * AA_SAMPLES];
	uint32_t	samples;
	t_ray		ray;

	samples = 0;
	i = 0;
	while (i < AA_SAMPLES)
	{
		j = 0;
		while (j < AA_SAMPLES)
		{
			ray = generate_ray(scene.camera, x + (double)i / AA_SAMPLES + 0.5
					/ AA_SAMPLES, y + (double)j / AA_SAMPLES + 0.5
					/ AA_SAMPLES);
			colors[samples++] = trace_single_ray(scene, ray);
			j++;
		}
		i++;
	}
	return (average_pixel_color(colors, samples));
}

void	raytrace(t_scene scene)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = compute_pixel_aa(scene, x, y);
			my_pixel_put(&scene.mlx_img, x, y, color);
			x++;
		}
		y++;
		if (y % 10 == 0)
		{
			ft_putnbr_fd((y * 100) / HEIGHT, STDOUT_FILENO);
			ft_putstr_fd("%\r", STDOUT_FILENO);
		}
	}
}
