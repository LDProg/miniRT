/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:16:16 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/11 16:52:55 by gaducurt         ###   ########.fr       */
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

	if (sphere->type == SP)
	{
		a = pow(ray.direction.x, 2) + pow(ray.direction.y, 2) + pow(ray.direction.z, 2);
		b = 2 * (ray.direction.x * (ray.origin.x - sphere->pos.x) + ray.direction.y * (ray.origin.y - sphere->pos.y) + ray.direction.z * (ray.origin.z - sphere->pos.z));
		c = (pow(ray.origin.x - sphere->pos.x, 2) + pow(ray.origin.z - sphere->pos.y, 2) + pow(ray.origin.z - sphere->pos.z, 2)) - pow(sphere->sp_diam / 2, 2);
		delta = pow(b, 2) - (4 * a * c);
		t = find_t(a, b, delta);
		// if (t == -1)
		// 	return (NULL);
		inter.pos = scalar_mult(ray.direction, t);
		inter.pos = add_vect_point(ray.direction, ray.origin);
		// inter.color = 0;
		return (inter);
	}
}
