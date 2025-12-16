/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:09:52 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/16 11:08:22 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	find_intersect(t_ray *ray, t_dynvec *tab_vec)
{
	t_obj	*obj;
	size_t	i;

	i = 0;
	ray->nb_inter = 0;
	ray->pix_color = 0;
	while (i <= tab_vec->len)
	{
		obj = (t_obj *)((unsigned char *)tab_vec->array + i * tab_vec->size_type);
		if (obj->type == SP)
			intersect_sphere(obj, ray);
		else if (obj->type == PL)
			intersect_plan(obj, ray);
		// else if (obj.type = CY)
		// 	intersect_cylinder(obj, ray);
		i++;
	}
	return (ray->pix_color);
}
