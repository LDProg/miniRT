/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:48:45 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/06 13:24:18 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libmath.h"
#include <stdio.h>

t_rgb	compute_color(double coef, t_rgb l_color, t_rgb o_color)
{
	t_rgb	c;

	c.r = (int)(coef * (l_color.r / 255.0) * (o_color.r / 255.0) * 255.0);
	c.g = (int)(coef * (l_color.g / 255.0) * (o_color.g / 255.0) * 255.0);
	c.b = (int)(coef * (l_color.b / 255.0) * (o_color.b / 255.0) * 255.0);
	return (c);
}

t_rgb	add_colors(t_rgb diff, t_rgb amb)
{
	t_rgb	c;

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
	c.rgb = ((int)c.r << 16) | ((int)c.g << 8) | (int)c.b;
	return (c);
}
