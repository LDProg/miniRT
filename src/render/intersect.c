/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 04:37:41 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/30 13:11:04 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include <math.h>

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

static bool	solve_quadatric(double a, double b, double c, double *t0,
		double *t1)
{
	double	discr;
	double	q;

	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (false);
	else if (discr == 0)
	{
		*t0 = -0.5 * b / a;
		*t1 = *t0;
	}
	else
	{
		if (b > 0)
			q = -0.5 * (b + sqrt(discr));
		else
			q = -0.5 * (b - sqrt(discr));
		*t0 = q / a;
		*t1 = c / q;
	}
	return (check_quadratic_roots(t0, t1));
}

static bool	hit_sphere(t_ray ray, t_sphere *sp, t_hit *hit)
{
	double	t0;
	double	t1;
	t_vec3	oc;
	double	a;
	double	b;
	double	c;

	oc = substract_tuple(ray.origin, sp->center);
	a = vec3_dot(ray.direction, ray.direction);
	b = 2 * vec3_dot(ray.direction, oc);
	c = vec3_dot(oc, oc) - sp->radius * sp->radius;
	if (solve_quadatric(a, b, c, &t0, &t1))
	{
		hit->t = t0;
		hit->color = sp->color;
		return (true);
	}
	return (false);
}

static bool	hit_plane(t_ray ray, t_plane *pl, t_hit *hit)
{
	(void)ray;
	(void)pl;
	(void)hit;
	return (false);
}

static bool	hit_cylinder(t_ray ray, t_cylinder *cy, t_hit *hit)
{
	(void)ray;
	(void)cy;
	(void)hit;
	return (false);
}

bool	hit_object(t_ray ray, t_obj *obj, t_hit *hit)
{
	if (obj->type == T_SPHERE)
		return (hit_sphere(ray, (t_sphere *)obj->shape, hit));
	if (obj->type == T_PLANE)
		return (hit_plane(ray, (t_plane *)obj->shape, hit));
	if (obj->type == T_CYLINDER)
		return (hit_cylinder(ray, (t_cylinder *)obj->shape, hit));
	return (false);
}
