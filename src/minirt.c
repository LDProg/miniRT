/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/05 14:30:38 by gaducurt         ###   ########.fr       */
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

t_tuple	fill_vect_test(float x, float y, float z, float w)
{
	t_tuple res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = w;
	return (res);
}

void	test_vect()
{
	t_tuple	v1;
	
	v1 = fill_vect_test(1, 2, 3, 0);
	printf(BLUE"x1 = %g\ny1 = %g\nz1 = %g\nw1 = %d\n\n"RESET, v1.x, v1.y, v1.z, v1.w);
	v1 = all_rotate_matrix(v1, 30, 15, 60);
	printf(GREEN"x1 = %g\ny1 = %g\nz1 = %g\nw1 = %d\n\n"RESET, v1.x, v1.y, v1.z, v1.w);
}

int	main(int ac, char **av)
{
	t_vector	*vector;
	int			fd;

	if (check_args(ac, av))
		return (1);
	fd = open(av[1], O_RDONLY);
	vector = malloc((sizeof(t_vector)));
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
	printf("Hello RT!\n");
	scene_init(&scene);
	init_camera(&scene, create_point(0, 0, 15), create_vector(0, 0, -1));
	mlx_loop(scene.mlx_ptr);
	return (EXIT_SUCCESS);
}
