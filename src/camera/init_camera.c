/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:12:16 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/29 02:19:18 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

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
	ray.direction = vector_normalize(ray.direction);
	return (ray);
}

static void	project_rays(t_camera camera)
{
	uint32_t	x;
	uint32_t	y;
	t_ray		ray;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = generate_ray(camera, x, y);
			x++;
		}
		y++;
	}
}

static t_camera	create_camera_basis(t_point3 origin, t_vec3 forward)
{
	t_camera	camera;
	t_vec3		world_up;

	camera.origin = origin;
	camera.forward = vector_normalize(forward);
	world_up = create_vector(0, 1, 0);
	if (fabs(camera.forward.y) > 0.999)
		world_up = create_vector(0, 0, 1);
	camera.right = vector_normalize(vector_cross(world_up, camera.forward));
	camera.up = vector_normalize(vector_cross(camera.forward, camera.right));
	return (camera);
}

t_camera	init_camera(t_point3 origin, t_vec3 forward)
{
	t_camera	camera;

	camera = create_camera_basis(origin, forward);
	project_rays(camera);
	return (camera);
}
