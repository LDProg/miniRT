/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/19 14:44:53 by gaducurt         ###   ########.fr       */
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
	p = (t_obj *)((unsigned char *)tab_vec->array + 1 * tab_vec->size_type);
	printf("Hello RT!\n");
	og_cam = p->pos;
	dir_cam = p->norm_v;
	scene_init(&scene);
	// init_camera(&scene, create_point(0, 0, 15), create_vector(0, 0, -1), tab_vec);
	init_camera(&scene, og_cam, dir_cam, tab_vec);
	mlx_loop(scene.mlx_ptr);
	return (EXIT_SUCCESS);
}
