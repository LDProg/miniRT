/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:16:49 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/11 16:16:30 by gaducurt         ###   ########.fr       */
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
