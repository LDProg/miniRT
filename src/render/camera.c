/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:12:16 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/30 12:23:42 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include <math.h>

t_camera	camera_init(t_point3 origin, t_vec3 forward)
{
	t_camera	camera;
	t_vec3		world_up;

	camera.origin = origin;
	camera.forward = vec3_normalize(forward);
	world_up = vec3_new(0, 1, 0);
	if (fabs(camera.forward.y) > 0.999)
		world_up = vec3_new(0, 0, 1);
	camera.right = vec3_normalize(vec3_cross(camera.forward, world_up));
	camera.up = vec3_normalize(vec3_cross(camera.right, camera.forward));
	return (camera);
}
