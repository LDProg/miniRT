/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/05 05:24:39 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "rt_structures.h"
#include "scene/camera.h"
#include "scene/setup.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_scene	scene;

	(void)ac;
	(void)av;
	printf("Hello RT!\n");
	scene_init(&scene);
	init_camera(&scene, create_point(0, 0, 15), create_vector(0, 0, -1));
	mlx_loop(scene.mlx_ptr);
	return (EXIT_SUCCESS);
}
