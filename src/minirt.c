/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/18 18:02:12 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing/parsing.h"
#include "dynvect.h"
#include <fcntl.h>
#include "mlx.h"
#include "rt_structures.h"
#include "scene/camera.h"
#include "scene/setup.h"
#include <stdio.h>
#include "mathvect.h"
#include "tests/tests.h"
#include "minirt.h"
#include <math.h>

int	main(int ac, char **av)
{
	t_scene		scene;
	t_dynvec	*tab_vec;
	t_point3	og_cam;
	t_vec3		dir_cam;
	// t_ray		ray;
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
	// ray = init_ray();
	// printf("ray.origin.x = %g\nray.origin.y = %g\nray.origin.z = %g\n\n", ray.origin.x, ray.origin.y, ray.origin.z);
	// printf("ray.direction.x = %g\nray.direction.y = %g\nray.direction.z = %g\n\n", ray.direction.x, ray.direction.y, ray.direction.z);
	// print_vector(vector);
	p = (t_obj *)((unsigned char *)tab_vec->array + 1 * tab_vec->size_type);
	// print_struct(p);
	// printf(RED"x = %g\ny = %g\nz = %g\n\n"RESET, inter.pos.x, inter.pos.y, inter.pos.z);
	// p = (t_obj *)((unsigned char *)tab_vec->array + 4 * tab_vec->size_type);
	// printf("ray.origin.x = %g\nray.origin.y = %g\nray.origin.z = %g\n\n", ray.origin.x, ray.origin.y, ray.origin.z);
	// printf("ray.direction.x = %g\nray.direction.y = %g\nray.direction.z = %g\n\n", ray.direction.x, ray.direction.y, ray.direction.z);
	// print_struct(p);
	// printf(RED"x = %g\ny = %g\nz = %g\n\n"RESET, inter.pos.x, inter.pos.y, inter.pos.z);
	printf("Hello RT!\n");
	og_cam = p->pos;
	dir_cam = p->norm_v;
	printf("og_cam = (%g, %g, %g)\ndir_cam = (%g, %g, %g)\n", og_cam.x, og_cam.y, og_cam.z, dir_cam.x, dir_cam.y, dir_cam.z);
	scene_init(&scene);
	// init_camera(&scene, create_point(0, 0, 15), create_vector(0, 0, -1), tab_vec);
	init_camera(&scene, og_cam, dir_cam, tab_vec);
	mlx_loop(scene.mlx_ptr);
	return (EXIT_SUCCESS);
}
