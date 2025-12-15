/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:12:16 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/15 15:21:49 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include "minirt.h"
#include "scene/setup.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

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

// static void	apply_camera_matrice(t_camera camera, t_ray ray)
// {
// 	t_point3	ray_origin;
// 	t_vec3		ray_origin_world;
// 	t_vec3		ray_p_world;
// 	t_mat4		cam_to_world_matrice;
// 	t_vec3		ray_direction;

// 	ray_origin = camera.origin;
// 	ray_origin_world = create_vector(0, 0, 0);
// 	ray_p_world = create_vector(0, 0, 0);
// 	cam_to_world_matrice = mat4_zero();
// 	mat4_mul_vec3(ray_origin, ray_origin_world);
// 	mat4_mul_vec3(ray.direction, ray_p_world);
// 	ray_direction = substract_tuple(ray_p_world - ray_origin_world);
// 	vector_normalize(ray_direction);
// }

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
	cam_y = (1 - 2 * ((y + 0.5) / HEIGHT)) * scale;
	ray.origin = camera.origin;
	// printf("ray.origin.x = %g\nray.origin.y = %g\nray.origin.z = %g\n", ray.origin.x, ray.origin.y, ray.origin.z);
	ray.direction = vector_normalize(create_vector(cam_x, cam_y, -1));
	// printf("ray.direction.x = %g\nray.direction.y = %g\nray.direction.z = %g\n", ray.direction.x, ray.direction.y, ray.direction.z);
	return (ray);
}

void	display_scene(t_pixel *pix_tab, t_mlx_img *mlx_img)
{
	int	i;

	i = 0;
	while (i <= HEIGHT * WIDTH)
	{
		my_pixel_put(mlx_img, pix_tab[i].x, pix_tab[i].y, pix_tab[i].color);
		i++;
	}
}

static void	project_rays(t_camera camera, t_dynvec *tab_vec, t_mlx_img *mlx_img)
{
	uint32_t	x;
	uint32_t	y;
	t_ray		ray;
	t_pixel		*pix_tab;
	int			i;

	y = 0;
	i = 0;
	pix_tab = malloc((HEIGHT * WIDTH) * sizeof(t_pixel));
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = get_ray(camera, x, y);
			find_intersect(&ray, tab_vec);
			// my_pixel_put(&scene->mlx_img, x, y, color);
			pix_tab[i].x = x;
			pix_tab[i].y = y;
			pix_tab[i].color = ray.pix_color;
			x++;
			i++;
		}
		y++;
	}
	printf("coucou\n");
	display_scene(pix_tab, mlx_img);
	free(pix_tab);
}

// t_point3 get_point(t_ray ray)
// {
// 	float t;
// }

t_camera	init_camera(t_scene *scene, t_point3 origin, t_vec3 direction, t_dynvec *tab_vec)
{
	t_camera camera;

	camera.origin = origin;
	camera.direction = vector_normalize(direction);
	project_rays(camera, tab_vec, &scene->mlx_img);
	scene->needs_redraw = true;
	return (camera);
}
