/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/30 13:13:49 by ludebion         ###   ########.fr       */
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
	scene->needs_redraw = true;
}

static void	objs_init(t_scene *scene)
{
	scene->objects = malloc(2 * sizeof(t_obj *));
	if (!scene->objects)
		return ;
	scene->objects[0] = create_sphere(point3_new(0.0, 0.0, -65.6), 20.6 / 2,
			get_color(160, 8, 255));
	if (!scene->objects[0])
	{
		free(scene->objects);
		return ;
	}
	scene->objects[1] = create_sphere(point3_new(10.0, 0.0, -62.6), 17.6 / 2,
			get_color(120, 30, 90));
	if (!scene->objects[1])
	{
		free(scene->objects[0]);
		free(scene->objects);
		return ;
	}
}

static void	init_scene(t_scene *scene)
{
	mlx_full_init(scene);
	scene->camera = camera_init(point3_new(0.0, 0.0, 10.0), vec3_new(0.0, 0.0,
				-1));
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
