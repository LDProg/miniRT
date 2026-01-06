/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 11:33:04 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "parsing/parsing.h"
#include "rt_structures.h"
#include "scene/mlx_window.h"
#include "scene/render.h"
#include <stdio.h>
#include <stdlib.h>

static void	render_scene(t_scene *scene)
{
	raytrace(scene->camera, scene->objects, &scene->mlx_img);
	mlx_put_image_to_window(scene->mlx_ptr, scene->window_ptr,
		scene->mlx_img.img_ptr, 0, 0);
	// scene->needs_redraw = true;
}

static void	objs_init(t_scene *scene)
{
	scene->objects = malloc(5 * sizeof(t_obj *));
	if (!scene->objects)
		return ;
	scene->objects[0] = create_sphere(point3_new(0.0, 0.0, -65), 20.6 / 2,
			get_color(205, 69, 120));
	if (!scene->objects[0])
	{
		free(scene->objects);
		return ;
	}
	scene->objects[1] = create_cylinder(point3_new(18.0, 0.0, -60), vec3_new(0,
				0, -1), 5, 15, get_color(0, 0, 205));
	if (!scene->objects[1])
	{
		free(scene->objects[0]);
		free(scene->objects);
		return ;
	}
	scene->objects[2] = create_cylinder(point3_new(-18.0, 0.0, -60), vec3_new(0,
				1, 0), 5, 15, get_color(0, 0, 205));
	// scene->objects[3] = create_plane(point3_new(0.0, 0.0, -90), vec3_new(0,
	// 0,
	// 			-1), get_color(129, 50, 175));
	// scene->objects[1] = create_sphere(point3_new(18.0, 0.0, -60), 17.6 / 2,
	// 		get_color(0, 0, 205));
	// if (!scene->objects[1])
	// {
	// 	free(scene->objects[0]);
	// 	free(scene->objects);
	// 	return ;
	// }
	// scene->objects[2] = create_sphere(point3_new(10.0, 0.0, -50), 14.6 / 2,
	// 		get_color(190, 70, 130));
	// scene->objects[3] = create_sphere(point3_new(-4.0, 0.0, -80), 35.6 / 2,
	// 		get_color(25, 120, 175));
	// scene->objects[4] = create_sphere(point3_new(7.0, 0.0, -60), 8.6 / 2,
	// 		get_color(179, 30, 90));
}

static void	init_scene(t_scene *scene)
{
	mlx_full_init(scene);
	// scene->camera = camera_init(point3_new(0.0, 0.0, 30.0), vec3_new(0.0,
	// 0.0,
	// 			-1));
	scene->camera = camera_init(point3_new(-25.0, 30.0, 20.0), vec3_new(0.3,
				-0.4, -1));
	// scene->objects = parsing;
	// scene->light = parsing;
	// scene->ambient = parsing;
	objs_init(scene);
}

int	main(int ac, char **av)
{
	t_scene	scene;

	(void)ac;
	(void)av;
	printf("Hello RT!\n");
	init_scene(&scene);
	render_scene(&scene);
	mlx_loop(scene.mlx_ptr);
	return (EXIT_SUCCESS);
}
