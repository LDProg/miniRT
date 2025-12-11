/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:13:59 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/11 16:23:14 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "rt_structures.h"
#include "utils/rt_utils.h"

int	handle_close_hook(t_scene *scene)
{
	close_program(scene, "Program close successfully.\n", 0, 0);
	return (0);
}

int	handle_mouse_hook(int button, int x, int y, t_scene *scene)
{
	(void)x;
	(void)y;
	if (button == MOUSE_DOWN || button == MOUSE_UP)
	{
		scene->needs_redraw = 1;
	}
	return (0);
}

int	handle_keypress_hook(int keycode, t_scene *scene)
{
	if (keycode == CLOSE_KEY)
		handle_close_hook(scene);
	return (0);
}

int	loop_hook(t_scene *scene)
{
	if (scene->needs_redraw)
	{
		// 	scene_render(scene);
		mlx_put_image_to_window(scene->mlx_ptr, scene->window_ptr,
			scene->mlx_img.img_ptr, 0, 0);
		scene->needs_redraw = false;
	}
	return (0);
}
