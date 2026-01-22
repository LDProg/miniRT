/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:12:16 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/22 11:49:36 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include <math.h>

void	camera_init(t_camera *camera)
{
	t_vec3	world_up;

	camera->forward = vec3_normalize(camera->forward);
	world_up = vec3_new(0, 1, 0);
	if (fabs(camera->forward.y) > 0.999)
		world_up = vec3_new(0, 0, 1);
	camera->right = vec3_normalize(vec3_cross(camera->forward, world_up));
	camera->up = vec3_normalize(vec3_cross(camera->right, camera->forward));
}
