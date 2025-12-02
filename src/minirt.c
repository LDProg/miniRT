/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/02 06:57:27 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "render/render.h"
#include "rt_structures.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_scene	scene;

	(void)ac;
	(void)av;
	printf("Hello RT!\n");
	scene_init(&scene);
	mlx_loop(scene.mlx_ptr);
	return (EXIT_SUCCESS);
}
