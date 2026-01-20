/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/10 06:41:06 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "parsing/parsing.h"
#include "rt_structures.h"
#include "scene/mlx_window.h"
#include "scene/render.h"
#include "utils/rt_utils.h"
#include <stdio.h>

static void	render_scene(t_scene scene)
{
	raytrace(scene);
	mlx_put_image_to_window(scene.mlx_ptr, scene.window_ptr,
		scene.mlx_img.img_ptr, 0, 0);
}

static void	init_scene(t_scene *scene, char *filename)
{
	t_error	err;

	ft_memset(scene, 0, sizeof(t_scene));
	scene->objs = malloc(sizeof(t_dynvec));
	if (!scene->objs)
		close_program(scene, ERR_MALLOC);
	ft_init_vector(scene->objs, sizeof(t_object));
	err = parse_file(scene, filename);
	if (err != ERR_NONE)
	{
		if (err == ERR_OPEN)
			perror(filename);
		close_program(scene, err);
	}
	mlx_full_init(scene);
	camera_init(&scene->camera);
}

int	main(int ac, char **av)
{
	t_scene	scene;

	if (!check_args(ac, av))
		return (EXIT_FAILURE);
	init_scene(&scene, av[1]);
	render_scene(scene);
	mlx_loop(scene.mlx_ptr);
	return (EXIT_SUCCESS);
}
