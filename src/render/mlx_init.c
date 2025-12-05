/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:13:46 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/05 04:30:48 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "rt_structures.h"
#include "scene/setup.h"
#include "utils/rt_utils.h"

static void	events_init(t_scene *scene)
{
	mlx_hook(scene->window_ptr, 17, 0, handle_close_hook, scene);
	mlx_key_hook(scene->window_ptr, handle_keypress_hook, scene);
	mlx_mouse_hook(scene->window_ptr, handle_mouse_hook, scene);
	mlx_loop_hook(scene->mlx_ptr, loop_hook, scene);
}

void	mlx_full_init(t_scene *scene)
{
	scene->mlx_ptr = mlx_init();
	if (!scene->mlx_ptr)
		close_program(scene, "Problems with mlx_init.\n", false, true);
	scene->window_ptr = mlx_new_window(scene->mlx_ptr, WIDTH, HEIGHT, "Scene");
	if (!scene->window_ptr)
		close_program(scene, "Problems creating window.\n", false, true);
	scene->mlx_img.img_ptr = mlx_new_image(scene->mlx_ptr, WIDTH, HEIGHT);
	if (!scene->mlx_img.img_ptr)
		close_program(scene, "Problems creating image.\n", false, true);
	scene->mlx_img.pixels_ptr = mlx_get_data_addr(scene->mlx_img.img_ptr,
			&scene->mlx_img.bpp, &scene->mlx_img.size_line,
			&scene->mlx_img.endian);
	if (!scene->mlx_img.pixels_ptr)
		close_program(scene, "Problems getting data address.\n", false, true);
	events_init(scene);
}
