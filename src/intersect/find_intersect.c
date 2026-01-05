/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:09:52 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/05 15:15:11 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_obj	*get_d_light(t_dynvec *tab_vec)
{
	t_obj	*obj;
	size_t	i;

	i = 0;
	while (i <= tab_vec->len)
	{
		obj = (t_obj *)((unsigned char *)tab_vec->array + i * tab_vec->size_type);
		if (obj->type == L)
			break;
		i++;
	}
	return (obj);
}

t_obj	*get_a_light(t_dynvec *tab_vec)
{
	t_obj	*obj;
	size_t	i;

	i = 0;
	while (i <= tab_vec->len)
	{
		obj = (t_obj *)((unsigned char *)tab_vec->array + i * tab_vec->size_type);
		if (obj->type == A)
			break;
		i++;
	}
	return (obj);
}

int	find_intersect(t_ray *ray, t_dynvec *tab_vec, t_obj *d_light, t_obj *a_light)
{
	t_obj	*obj;
	size_t	i;

	i = 0;
	ray->nb_inter = 0;
	ray->pix_color.rgb = 0;
	while (i <= tab_vec->len)
	{
		obj = (t_obj *)((unsigned char *)tab_vec->array + i * tab_vec->size_type);
		if (obj->type == SP)
			intersect_sphere(obj, ray, d_light, a_light);
		else if (obj->type == PL)
			intersect_plan(obj, ray);
		// else if (obj.type = CY)
		// 	intersect_cylinder(obj, ray);
		i++;
	}
	return (ray->pix_color.rgb);
}
