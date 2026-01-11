/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:16:16 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/11 16:11:38 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include <math.h>

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

static void	ft_swap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static bool	check_quadratic_roots(double *t0, double *t1)
{
	if (*t0 > *t1)
		ft_swap(t0, t1);
	if (*t0 < 0 && *t1 < 0)
		return (false);
	if (*t0 < 0)
		*t0 = *t1;
	return (true);
}

static double	find_t(double a, double b, double c, double delta)
{
	double	t1;
	double	t2;
	double	q;

	if (delta == 0)
		return (-0.5 * b / a);
	if (b > 0)
		q = -0.5 * (b + sqrt(delta));
	else
		q = -0.5 * (b - sqrt(delta));
	t1 = q / a;
	t2 = c / q;
	if (check_quadratic_roots(&t1, &t2))
		return (t1);
	return (NAN);
}

static void	comput_hit(double t, t_ray ray, t_hit *hit, t_sphere sp)
{
	hit->t = t;
	hit->point = adding_tuple(ray.origin,
			tuple_mul_scalar(ray.direction, t));
	hit->normal = tuple_div_scalar(substract_tuple(hit->point,
				sp.center), sp.radius);
	hit->shape_color = sp.color;
}

bool	intersect_sphere(t_ray ray, t_sphere sp, t_hit *hit)
{
	double	a;
	double	b;
	double	c;
	double	t;
	double	delta;

	a = vec3_dot(ray.direction, ray.direction);
	b = 2 * (ray.direction.x * (ray.origin.x - sp.center.x) + ray.direction.y
			* (ray.origin.y - sp.center.y) + ray.direction.z * (ray.origin.z
				- sp.center.z));
	c = (pow(ray.origin.x - sp.center.x, 2) + pow(ray.origin.y - sp.center.y, 2)
			+ pow(ray.origin.z - sp.center.z, 2)) - pow(sp.radius, 2);
	delta = pow(b, 2) - (4 * a * c);
	if (delta >= 0)
	{
		t = find_t(a, b, c, delta);
		if (!isnan(t))
		{
			comput_hit(t, ray, hit, sp);
			return (true);
		}
	}
	return (false);
}

// void	intersect_sphere(t_obj *sphere, t_ray *ray, t_obj *d_light,
// 		t_obj *a_light)
// {
// 	double	a;
// 	double	b;
// 	double	c;
// 	double	t;
// 	double	delta;

// 	a = dot_product(ray->direction, ray->direction);
// b = 2 * (ray->direction.x * (ray->origin.x - sphere->pos.x)
// 		+ ray->direction.y * (ray->origin.y - sphere->pos.y)
// 		+ ray->direction.z * (ray->origin.z - sphere->pos.z));
// c = (pow(ray->origin.x - sphere->pos.x, 2) + pow(ray->origin.y
// 			- sphere->pos.y, 2) + pow(ray->origin.z - sphere->pos.z, 2))
// 	- pow(sphere->sp_diam / 2, 2);
// delta = pow(b, 2) - (4 * a * c);
// 	if (delta >= 0)
// 	{
// 		t = find_t(a, b, delta);
// 		if (ray->nb_inter == 0)
// 			handle_ray(t, ray, sphere, d_light, a_light);
// 		else if (ray->nb_inter > 0 && t < ray->t)
// 			handle_ray(t, ray, sphere, d_light, a_light);
// 		ray->nb_inter++;
// 	}
// }
