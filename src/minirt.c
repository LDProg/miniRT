/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/08 13:18:30 by gaducurt         ###   ########.fr       */
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
#include "minirt.h"



int	main(int ac, char **av)
{
	t_scene		scene;
	t_dynvec	*vector;
	t_point3	point;
	t_ray		ray;
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
	if (fill_tab(fd, vector))
	{
		ft_putstr_fd("The file is not valid", 2);
		return (1);
	}
	// test_vect();
	ray = init_ray();
	point = position(ray.origin, ray.direction, 0);
	print_tuple(point);
	printf("Hello RT!\n");
	scene_init(&scene);
	init_camera(&scene, create_point(0, 0, 15), create_vector(0, 0, -1));
	mlx_loop(scene.mlx_ptr);
	return (EXIT_SUCCESS);
}
