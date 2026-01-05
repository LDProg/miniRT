/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:48:45 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/05 14:01:01 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libmath.h"
#include <stdio.h>

t_color	compute_color(double coef, t_color l_color, t_color o_color)
{
	t_color	c;
	// int	final_color;
	// int	r;
	// int	g;
	// int	b;

	// printf(GREEN"coef = %g\nl_color.rgb = %d\nr = %g\ng = %g\nb = %g\n\n"RESET, coef, l_color.rgb, l_color.r, l_color.g, l_color.b);
	// printf(BLUE"coef = %g\no_color.rgb = %d\nr = %g\ng = %g\nb = %g\n\n"RESET, coef, o_color.rgb, o_color.r, o_color.g, o_color.b);
	c.b = (int)(coef * (l_color.r / 255.0) * (o_color.r / 255.0) * 255.0);
	c.g = (int)(coef * (l_color.g / 255.0) * (o_color.g / 255.0) * 255.0);
	c.b = (int)(coef * (l_color.b / 255.0) * (o_color.b / 255.0) * 255.0);
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
	// printf(RED"coef = %g\nrgb = %d\nr = %d\ng = %d\nb = %d\n\n"RESET, coef, final_color, r, g, b);
	// return (final_color);
	return (c);
}
