/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:15:38 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/30 11:33:39 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "rt_structures.h"
#include <math.h>
#include <stdlib.h>

uint32_t	get_color(double red, double green, double blue)
{
	return (((uint32_t)red << 16) | ((uint32_t)green << 8) | (uint32_t)blue);
}

void	my_pixel_put(t_mlx_img *img, uint32_t x, uint32_t y, uint32_t color)
{
	*(uint32_t *)(img->pixels_ptr + (y * img->size_line) + (x * (img->bpp
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
