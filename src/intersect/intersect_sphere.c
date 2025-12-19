/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:16:16 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/19 15:28:56 by gaducurt         ###   ########.fr       */
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

double	get_angle(t_vec3 l, t_vec3 n)
{
	double	angle;

	angle = dot_product(l, n);
	if (angle < 0)
		return (0);
	return (angle);
}

/*
Diffuse color = ratio * max(l.n, 0) * src_color * obj_color
*/

int	diffuse_lt(t_ray *ray, t_obj *obj, t_obj *light)
{
	t_vec3	normal;
	t_vec3	vec_light;
	double	angle;

	if (obj->type == SP)
	{
		normal = sub_two_points(ray->pos_inter, obj->pos);
		normal = normalize_vect(normal);
	}
	if (obj->type == PL)
		normal = obj->norm_v;
	vec_light = sub_two_points(light->pos, ray->pos_inter);
	vec_light = normalize_vect(vec_light);
	angle = get_angle(vec_light, normal);
	ray->pix_color = compute_color(light->lt_ratio * angle, light->color,
			obj->color);
	return (ray->pix_color);
}

void	handle_ray(double t, t_ray *ray, t_obj *obj, t_obj *light)
{
	ray->t = t;
	ray->pos_inter = scalar_mult(ray->direction, ray->t);
	ray->pos_inter = add_vect_point(ray->pos_inter, ray->origin);
	ray->pix_color = diffuse_lt(ray, obj, light);
}

void	intersect_sphere(t_obj *sphere, t_ray *ray, t_obj *light)
{
	double		a;
	double		b;
	double		c;
	double		t;
	double		delta;

	a = dot_product(ray->direction, ray->direction);
	b = 2 * (ray->direction.x * (ray->origin.x - sphere->pos.x)
			+ ray->direction.y * (ray->origin.y - sphere->pos.y)
			+ ray->direction.z * (ray->origin.z - sphere->pos.z));
	c = (pow(ray->origin.x - sphere->pos.x, 2)
			+ pow(ray->origin.y - sphere->pos.y, 2)
			+ pow(ray->origin.z - sphere->pos.z, 2))
		- pow(sphere->sp_diam / 2, 2);
	delta = pow(b, 2) - (4 * a * c);
	if (delta >= 0)
	{
		t = find_t(a, b, delta);
		if (ray->nb_inter == 0)
			handle_ray(t, ray, sphere, light);
		else if (ray->nb_inter > 0 && t < ray->t)
			handle_ray(t, ray, sphere, light);
		ray->nb_inter++;
	}
}
