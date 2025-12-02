/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 06:08:40 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/02 06:10:15 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render/render.h"
#include "rt_structures.h"

void	scene_init(t_scene *scene)
{
	mlx_full_init(scene);
	scene->needs_redraw = true;
}
