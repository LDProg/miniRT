/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:15:38 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/06 14:03:31 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "rt_structures.h"
#include <math.h>
#include <stdlib.h>

// static inline int	get_color(t_scene *scene, int iterations)
// {
// 	double	frequency;
// 	double	blue;
// 	double	green;
// 	double	red;

// 	(void)scene;
// 	frequency = 0.1;
// 	blue = sin(frequency * iterations) * 127 + 128;
// 	green = sin(frequency * iterations + 2.094) * 127 + 128;
// 	red = sin(frequency * iterations + 4.188) * 127 + 128;
// 	return (((int)red << 16) | ((int)green << 8) | (int)blue);
// }

void	my_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	*(unsigned int *)(img->pixels_ptr + (y * img->size_line) + (x * (img->bpp
					/ 8))) = color;
}

void	mlx_clear(t_scene *scene)
{
	if (scene->mlx_img.img_ptr)
		mlx_destroy_image(scene->mlx_ptr, scene->mlx_img.img_ptr);
	if (scene->window_ptr)
		mlx_destroy_window(scene->mlx_ptr, scene->window_ptr);
	if (scene->mlx_ptr)
	{
		mlx_destroy_display(scene->mlx_ptr);
		free(scene->mlx_ptr);
	}
}
