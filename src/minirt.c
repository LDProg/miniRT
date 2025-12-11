/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/11 16:53:32 by gaducurt         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_scene		scene;
	t_dynvec	*vector;
	t_ray		ray;
	t_obj		*p;
	t_inter		inter;
	int			fd;

	if (check_args(ac, av))
		return (1);
	fd = open(av[1], O_RDONLY);
	vector = malloc((sizeof(t_dynvec)));
	if (!vector)
	{
		close(fd);
		return (1);
	}
	// vector = fill_tab(fd, vector);
	// if (!vector)
	if (fill_tab(fd, vector))
	{
		ft_putstr_fd("The file is not valid", 2);
		return (1);
	}
	ray = init_ray();
	// print_vector(vector);
	p = (t_obj *)((unsigned char *)vector->array + 3 * vector->size_type);
	print_struct(p);
	inter = intersect_sphere(p, ray);
	printf(RED"x = %g\ny = %g\nz = %g\n\n"RESET, inter.pos.x, inter.pos.y, inter.pos.z);
	printf("Hello RT!\n");
	scene_init(&scene);
	init_camera(&scene, create_point(0, 0, 15), create_vector(0, 0, -1));
	mlx_loop(scene.mlx_ptr);
	return (EXIT_SUCCESS);
}
