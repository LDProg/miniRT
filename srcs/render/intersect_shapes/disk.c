/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 08:54:39 by ludebion          #+#    #+#             */
/*   Updated: 2026/02/01 08:56:59 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene/intersect_shapes.h"

bool	hit_disk(t_ray ray, t_plane pl, t_hit *hit)
{
	t_vec3	v_cy_center_to_p;
	double	d2;

	if (hit_plane(ray, pl, hit))
	{
		v_cy_center_to_p = substract_tuple(hit->point, pl.center);
		d2 = vec3_dot(v_cy_center_to_p, v_cy_center_to_p);
		if (d2 <= pl.radius * pl.radius)
			return (true);
	}
	return (false);
}
