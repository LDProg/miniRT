/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 06:08:40 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/05 04:30:57 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include "scene/setup.h"

void	scene_init(t_scene *scene)
{
	mlx_full_init(scene);
	scene->needs_redraw = true;
}
