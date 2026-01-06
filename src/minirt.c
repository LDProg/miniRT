/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 14:13:55 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing/parsing.h"
#include "dynvect.h"
#include <fcntl.h>
#include "mlx.h"
#include "rt_structures.h"
#include "scene/mlx_window.h"
#include "scene/render.h"
#include <stdio.h>
#include "mathvect.h"
#include "tests/tests.h"
#include "minirt.h"
#include <math.h>

static void	render_scene(t_scene *scene, t_obj *cam)
{
	raytrace(scene->camera, scene->objects, &scene->mlx_img, cam);
	mlx_put_image_to_window(scene->mlx_ptr, scene->window_ptr,
		scene->mlx_img.img_ptr, 0, 0);
	// scene->needs_redraw = true;
}

static void	objs_init(t_scene *scene)
{
	scene->objects = malloc(5 * sizeof(t_obj_lu *));
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
	t_scene		scene;
	t_dynvec	*tab_vec;
	// t_point3	og_cam;
	// t_vec3		dir_cam;
	t_obj		*p;
	int			fd;

	if (check_args(ac, av))
		return (1);
	fd = open(av[1], O_RDONLY);
	tab_vec = malloc((sizeof(t_dynvec)));
	if (!tab_vec)
	{
		close(fd);
		return (1);
	}
	if (fill_tab(fd, tab_vec))
	{
		ft_putstr_fd("The file is not valid", 2);
		return (1);
	}
	p = get_cam(tab_vec);
	// p = (t_obj *)((unsigned char *)tab_vec->array + 1 * tab_vec->size_type);
	printf("Hello RT!\n");
	// og_cam = p->pos;
	// dir_cam = p->norm_v;
	// scene_init(&scene);
	// init_camera(&scene, create_point(0, 0, 15), create_vector(0, 0, -1), tab_vec);
	// init_camera(&scene, tab_vec, p);
	camera_init(p->pos, p->norm_v);
	// init_camera(&scene, p->pos, p->norm_v, tab_vec, p->fov);

	init_scene(&scene);
	render_scene(&scene, p);
	mlx_loop(scene.mlx_ptr);
	return (EXIT_SUCCESS);
}
