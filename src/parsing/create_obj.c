/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:48:43 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 13:33:52 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include <stdlib.h>

t_obj_lu	*create_plane(t_point3 center, t_vec3 normal, uint32_t rgb)
{
	t_obj_lu	*obj;
	t_plane	*pl;

	obj = malloc(sizeof(t_obj_lu));
	if (!obj)
		return (NULL);
	pl = malloc(sizeof(t_plane));
	if (!pl)
	{
		free(obj);
		return (NULL);
	}
	pl->center = center;
	pl->normal = normal;
	pl->color.rgb = rgb;
	obj->type = T_PLANE;
	obj->shape = pl;
	return (obj);
}

t_obj_lu	*create_sphere(t_point3 center, double radius, uint32_t rgb)
{
	t_obj_lu		*obj;
	t_sphere	*sp;

	obj = malloc(sizeof(t_obj_lu));
	if (!obj)
		return (NULL);
	sp = malloc(sizeof(t_sphere));
	if (!sp)
	{
		free(obj);
		return (NULL);
	}
	sp->center = center;
	sp->radius = radius;
	sp->color.rgb = rgb;
	obj->type = T_SPHERE;
	obj->shape = sp;
	return (obj);
}

t_obj_lu	*create_cylinder(t_point3 center, t_point3 vz, double radius,
		double height, uint32_t rgb)
{
	t_obj_lu		*obj;
	t_cylinder	*cy;

	obj = malloc(sizeof(t_obj_lu));
	if (!obj)
		return (NULL);
	cy = malloc(sizeof(t_cylinder));
	if (!cy)
	{
		free(obj);
		return (NULL);
	}
	cy->center = center;
	cy->c_top = adding_tuple(center, tuple_mul_scalar(vz, height / 2));
	cy->c_bottom = substract_tuple(center, tuple_mul_scalar(vz, height / 2));
	cy->axis = vz;
	cy->radius = radius;
	cy->height = height;
	cy->color.rgb = rgb;
	obj->type = T_CYLINDER;
	obj->shape = cy;
	return (obj);
}
