/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:27:57 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/09 13:15:59 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include "minirt.h"
#include <stdio.h>

// void	intersect_plan(t_obj *plan, t_ray *ray)
// {
// 	t_vec3	norm;
// 	double	x;
// 	double	y;
// 	double	z;
// 	double	d;
// 	double	t;

// 	norm = plan->norm_v;
// 	x = ray->origin.x - plan->pos.x;
// 	y = ray->origin.y - plan->pos.y;
// 	z = ray->origin.z - plan->pos.z;
// 	d = -(norm.x + norm.y + norm.z);
// 	t = -((norm.x * x + norm.y * y + norm.z * z + d) / (norm.x * ray->direction.x + norm.y * ray->direction.y + norm.z * ray->direction.z));
// 	if (t > 0)
// 	{
// 		if (ray->nb_inter == 0)
// 		{
// 			ray->pix_color = plan->color;
// 			ray->t = t;
// 			ray->pos_inter = scalar_mult(ray->direction, ray->t);
// 			ray->pos_inter = add_vect_point(ray->pos_inter, ray->origin);
// 		}
// 		else if (ray->nb_inter > 0 && t < ray->t)
// 		{
// 			ray->pix_color = plan->color;
// 			ray->t = t;
// 			ray->pos_inter = scalar_mult(ray->direction, ray->t);
// 			ray->pos_inter = add_vect_point(ray->pos_inter, ray->origin);
// 		}
// 		ray->nb_inter++;
// 	}
// }
