/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:16:16 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/07 14:47:03 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libmath.h"
#include "structures.h"
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

void	intersect_sphere(t_ray *ray, t_obj *sp, t_obj *d_light, t_obj *a_light)
{
	double		a;
	double		b;
	double		c;
	double		t;
	double		delta;

	a = dot_product(ray->direction, ray->direction);
	b = 2 * (ray->direction.x * (ray->origin.x - sp->pos.x)
			+ ray->direction.y * (ray->origin.y - sp->pos.y)
			+ ray->direction.z * (ray->origin.z - sp->pos.z));
	c = (pow(ray->origin.x - sp->pos.x, 2)
			+ pow(ray->origin.y - sp->pos.y, 2)
			+ pow(ray->origin.z - sp->pos.z, 2))
		- pow(sp->sp_diam / 2, 2);
	delta = pow(b, 2) - (4 * a * c);
	if (delta >= 0)
	{
		// t = find_t(a, b, delta);
		if (ray->hit.nb_inter == 0 || (ray->hit.nb_inter > 0 && find_t(a, b, delta) < ray->hit.t))
			ray->hit.t = find_t(a, b, delta);
		ray->hit.normal = sub_two_points(ray->hit.point, sp->pos);
		ray->hit.normal = normalize_vect(ray->hit.normal);
		// if (ray->hit.nb_inter == 0)
		// 	handle_ray(ray, sp, d_light, a_light);
		// else if (ray->hit.nb_inter > 0 && t < ray->hit.t)
		// 	handle_ray(ray, sp, d_light, a_light);
		ray->hit.nb_inter++;
	}
}
