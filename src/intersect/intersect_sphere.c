/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:16:16 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/12 17:53:50 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libmath.h"
#include <math.h>
#include <stdio.h>

/*
Equation du ray : O + dir * t
- O		: point de départ
- dir	: direction
- t		: distance parcourue par le ray

Equation de la sphere : (X - Xc)² + (Y - Yc)² + (Z - Zc)² = r²
- X, Y, Z		: inconues
- Xc, Yc, Zc	: cente de la sphere
- r				: rayon de la sphere

Après simplification on tombe sur une equation du second degré dont la seule
inconue est t.
a = dir.x² + dir.y² + dir.z²
b = 2 * (dir.x * (O.x - Xc) + dir.y * (O.y - Yc) + dir.z * (O.z - Zc))
c = ((O.x - Xc)² + (O.y - Yc)² + (O.z - Zc)²) - r²

Dleta = b² - 4ac
t1 = (-b + sqrt(delta)) / 2a
t2 = (-b - sqrt(delta)) / 2a

On prend l'intersection la plus proche.
*/

double	find_t(double a, double b, double delta)
{
	double	t1;
	double	t2;

	if (delta < 0)
		return (-1);
	printf(BLUE"delta = %g\n"RESET, delta);
	printf(GREEN"t = %g\n"RESET, -b / (2 * a));
	if (delta == 0)
		return (-b / (2 * a));
	t1 = (-b + sqrtf(delta)) / (2 * a);
	t2 = (-b - sqrtf(delta)) / (2 * a);
	if (t1 < t2)
		return (t1);
	return (t2);
}

t_inter	intersect_sphere(t_obj *sphere, t_ray ray)
{
	t_inter	inter;
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t;

	inter.pos.x = 0;
	inter.pos.y = 0;
	inter.pos.z = 0;
	inter.pos.w = 0;
	if (sphere->type == SP)
	{
		a = pow(ray.direction.x, 2) + pow(ray.direction.y, 2) + pow(ray.direction.z, 2);
		// printf(BLUE"a = %g\n"RESET, a);
		b = 2 * (ray.direction.x * (ray.origin.x - sphere->pos.x) + ray.direction.y * (ray.origin.y - sphere->pos.y) + ray.direction.z * (ray.origin.z - sphere->pos.z));
		// printf(BLUE"b = %g\n"RESET, b);
		printf(GREEN"ray.origin.x = %g\nsphere->pos.x = %g\nray.origin.y = %g\nsphere->pos.y = %g\nray.origin.z = %g\nsphere->pos.z = %g\n\n"RESET, ray.origin.x, sphere->pos.x, ray.origin.y, sphere->pos.y, ray.origin.z, sphere->pos.z);
		c = (pow(ray.origin.x - sphere->pos.x, 2) + pow(ray.origin.y - sphere->pos.y, 2) + pow(ray.origin.z - sphere->pos.z, 2)) - pow(sphere->sp_diam / 2, 2);
		// printf(BLUE"c = %g\n"RESET, c);
		delta = pow(b, 2) - (4 * a * c);
		// printf(BLUE"delta = %g\n"RESET, delta);
		t = find_t(a, b, delta);
		// printf(BLUE"sphere.t = %g\n"RESET, t);
		inter.pos = scalar_mult(ray.direction, t);
		// printf(BLUE"inter.pos.x = %g\ninter.pos.y = %g\ninter.pos.z = %g\n\n"RESET, inter.pos.x, inter.pos.y, inter.pos.z);
		inter.pos = add_vect_point(ray.direction, ray.origin);
		// printf(BLUE"inter.pos.x = %g\ninter.pos.y = %g\ninter.pos.z = %g\n\n"RESET, inter.pos.x, inter.pos.y, inter.pos.z);
		return (inter);
	}
	return (inter);
}
