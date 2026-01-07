/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:48:45 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/07 11:33:47 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libmath.h"
#include <stdio.h>

t_color	compute_color(double coef, t_color l_color, t_color o_color)
{
	t_color	c;

	c.r = (int)(coef * (l_color.r / 255.0) * (o_color.r / 255.0) * 255.0);
	c.g = (int)(coef * (l_color.g / 255.0) * (o_color.g / 255.0) * 255.0);
	c.b = (int)(coef * (l_color.b / 255.0) * (o_color.b / 255.0) * 255.0);
	return (c);
}

t_color	add_colors(t_color diff, t_color amb)
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
	c.rgb = ((int)c.r << 16) | ((int)c.g << 8) | (int)c.b;
	return (c);
}
