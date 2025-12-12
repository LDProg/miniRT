/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:27:57 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/12 13:49:13 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include "minirt.h"

t_inter	intersect_plan(t_obj *plan, t_ray ray)
{
	t_inter	inter;
	t_vec3	norm;
	double	x;
	double	y;
	double	z;
	double	t;
	double	d;

	norm = plan->norm_v;
	x = ray.origin.x - plan->pos.x;
	y = ray.origin.y - plan->pos.y;
	z = ray.origin.z - plan->pos.z;
	inter.pos.x = 0;
	inter.pos.y = 0;
	inter.pos.z = 0;
	inter.pos.w = 0;
	d = -(norm.x + norm.y + norm.z);
	if (plan->type == PL)
	{
		t = -((norm.x * x + norm.y * y + norm.z * z) / (norm.x * ray.direction.x + norm.y * ray.direction.y + norm.z * ray.direction.z));
		inter.pos = scalar_mult(ray.direction, t);
		inter.pos = add_vect_point(ray.direction, ray.origin);
		return (inter);
	}
	return (inter);
}
