/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:15:31 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/20 16:41:53 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include "utils/rt_utils.h"

uint32_t	average_pixel_color(uint32_t *pixel_colors, uint32_t samples)
{
	uint32_t	i;
	uint32_t	total_r;
	uint32_t	total_g;
	uint32_t	total_b;
	t_color		color;

	i = 0;
	total_r = 0;
	total_g = 0;
	total_b = 0;
	while (i < samples)
	{
		extract_rgb(pixel_colors[i], &color);
		total_r += color.r;
		total_g += color.g;
		total_b += color.b;
		i++;
	}
	return (get_color(total_r / samples, total_g / samples, total_b / samples));
}

t_color	compute_color(double coef, t_color l_color, t_color o_color)
{
	t_color	c;

	c.r = (int)(coef * (l_color.r / 255.0) * (o_color.r / 255.0) * 255.0);
	c.g = (int)(coef * (l_color.g / 255.0) * (o_color.g / 255.0) * 255.0);
	c.b = (int)(coef * (l_color.b / 255.0) * (o_color.b / 255.0) * 255.0);
	return (c);
}

uint32_t	add_colors(t_color diff, t_color amb)
{
	t_color	c;

	c.r = diff.r + amb.r;
	c.g = diff.g + amb.g;
	c.b = diff.b + amb.b;
	if (c.r > 255)
		c.r = 255;
	if (c.r < 0)
		c.r = 0;
	if (c.g > 255)
		c.g = 255;
	if (c.g < 0)
		c.g = 0;
	if (c.b > 255)
		c.b = 255;
	if (c.b < 0)
		c.b = 0;
	return (((int)c.r << 16) | ((int)c.g << 8) | (int)c.b);
}
