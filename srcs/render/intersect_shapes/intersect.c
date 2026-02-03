/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:18:11 by ludebion          #+#    #+#             */
/*   Updated: 2026/02/01 08:36:59 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/intersect_shapes.h"

static bool	hit_object(t_ray ray, t_object *obj, t_hit *hit)
{
	if (obj->type == T_SPHERE)
		return (hit_sphere(ray, obj->shape.sphere, hit));
	else if (obj->type == T_PLANE)
		return (hit_plane(ray, obj->shape.plane, hit));
	else if (obj->type == T_CYLINDER)
		return (hit_cylinder(ray, obj->shape.cylinder, hit));
	else if (obj->type == T_CONE)
		return (hit_cone(ray, obj->shape.cone, hit));
	return (false);
}

bool	intersect_scene_objects(t_dynvec *objs, t_ray ray, t_hit *hit)
{
	size_t	i;
	bool	has_hit;
	t_hit	tmp_hit;

	i = 0;
	has_hit = false;
	while (i < objs->len)
	{
		if (hit_object(ray, &((t_object *)objs->array)[i], &tmp_hit))
		{
			if (!has_hit || tmp_hit.t < hit->t)
				*hit = tmp_hit;
			has_hit = true;
		}
		i++;
	}
	return (has_hit);
}
