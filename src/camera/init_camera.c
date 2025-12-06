/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:12:16 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/06 14:14:30 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include <math.h>
#include <stdint.h>

static t_ray	pixels_coordinates_to_ray(t_camera camera, uint32_t x,
		uint32_t y)
{
	t_ray	ray;
	double	scale;
	t_vec3	v;

	scale = tan((FOV * 0.5) * (M_PI / 180.0));
	v = create_vector(x - WIDTH / 2, HEIGHT / 2 - y, -(HEIGHT / 2) / scale);
	ray.origin = camera.origin;
	ray.direction = vector_normalize(v);
	return (ray);
}

static t_ray	get_ray(t_camera camera, uint32_t x, uint32_t y)
{
	t_ray	ray;
	double	cam_x;
	double	cam_y;
	double	aspect_ratio;
	double	scale;

	scale = tan((FOV * 0.5) * (M_PI / 180.0));
	aspect_ratio = (double)WIDTH / HEIGHT;
	cam_x = (2 * ((x + 0.5) / WIDTH) - 1) * aspect_ratio * scale;
	cam_y = (1 - 2 * ((y + 0.5) / HEIGHT) * scale);
	ray.origin = camera.origin;
	ray.direction = vector_normalize(create_vector(cam_x, cam_y,
				camera.forward.z));
	return (ray);
}

static void	project_rays(t_camera camera)
{
	uint32_t	x;
	uint32_t	y;
	t_ray		ray;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			ray = get_ray(camera, x, y);
			// my_pixel_put(&scene->mlx_img, x, y, color);
			x++;
		}
		y++;
	}
}

t_camera	init_camera(t_scene *scene, t_point3 origin, t_vec3 direction)
{
	t_camera	camera;

	camera.origin = origin;
	camera.direction = vector_normalize(direction);
	project_rays(camera);
	scene->needs_redraw = true;
	return (camera);
}
