/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:48:45 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/19 11:59:41 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libmath.h"
#include <stdio.h>

int	compute_color(double coef, t_color l_color, t_color o_color)
{
	int	final_color;
	int	r;
	int	g;
	int	b;

	// printf(GREEN"coef = %g\nl_color.rgb = %d\nr = %g\ng = %g\nb = %g\n\n"RESET, coef, l_color.rgb, l_color.r, l_color.g, l_color.b);
	// printf(BLUE"coef = %g\no_color.rgb = %d\nr = %g\ng = %g\nb = %g\n\n"RESET, coef, o_color.rgb, o_color.r, o_color.g, o_color.b);
	r = (int)(coef * (l_color.r / 255.0) * (o_color.r / 255.0) * 255.0);
	g = (int)(coef * (l_color.g / 255.0) * (o_color.g / 255.0) * 255.0);
	b = (int)(coef * (l_color.b / 255.0) * (o_color.b / 255.0) * 255.0);
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	final_color = (r << 16) | (g << 8) | b;
	// printf(RED"coef = %g\nrgb = %d\nr = %d\ng = %d\nb = %d\n\n"RESET, coef, final_color, r, g, b);
	// return (final_color);
	return (final_color);
}
