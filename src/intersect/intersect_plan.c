/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:27:57 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/15 13:30:26 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include "minirt.h"
#include <stdio.h>

void	intersect_plan(t_obj *plan, t_ray *ray)
{
	t_vec3		norm;
	t_point3	pos;
	double		x;
	double		y;
	double		z;
	double		d;

	norm = plan->norm_v;
	x = ray->origin.x - plan->pos.x;
	y = ray->origin.y - plan->pos.y;
	z = ray->origin.z - plan->pos.z;
	d = -(norm.x + norm.y + norm.z);
	if (plan->type == PL)
	{
		ray->t = -((norm.x * x + norm.y * y + norm.z * z + d) / (norm.x * ray->direction.x + norm.y * ray->direction.y + norm.z * ray->direction.z));
		// printf("t = %g = -((%g * %g + %g * %g + %g * %g + %g) / (%g * %g + %g * %g + %g * %g))\n", ray->t, norm.x, x, norm.y, y, norm.z, z, d, norm.x, ray->direction.x, norm.y, ray->direction.y, norm.z, ray->direction.z);
		// printf(BLUE"plan.t = %g\n"RESET, ray->t);
		pos = scalar_mult(ray->direction, ray->t);
		pos = add_vect_point(ray->direction, ray->origin);
		ray->pix_color = plan->color;
	}
}
