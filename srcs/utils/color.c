/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:16:49 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/10 10:30:48 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"

uint32_t	get_color(double red, double green, double blue)
{
	return (((uint32_t)red << 16) | ((uint32_t)green << 8) | (uint32_t)blue);
}

void	extract_rgb(uint32_t rgb, t_color *color)
{
	color->r = (rgb >> 16) & 0xFF;
	color->g = (rgb >> 8) & 0xFF;
	color->b = rgb & 0xFF;
}

bool	is_valid_color(int r, int g, int b)
{
	return (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255);
}

uint32_t	graduate_background(double y)
{
	double	a;
	double	r;
	double	g;
	double	b;

	a = 0.5 * y + 1;
	if (a < 0)
		a = 0;
	if (a > 1)
		a = 1;
	r = (1 - a) * 255.0 + a * 127.995;
	g = (1 - a) * 255.0 + a * 179.1993;
	b = (1 - a) * 255.0 + a * 255.999;
	return (get_color(r, g, b));
}

uint32_t	normal_color(t_vec3 p, t_point3 center)
{
	t_vec3	normal;
	double	r;
	double	g;
	double	b;

	normal = vec3_normalize(substract_tuple(p, center));
	r = 0.5 * (255.999 * (normal.x + 1));
	g = 0.5 * (255.999 * (normal.y + 1));
	b = 0.5 * (255.999 * (normal.z + 1));
	return (get_color(r, g, b));
}

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
