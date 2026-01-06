/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:17:19 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 11:39:56 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "rt_structures.h"

t_camera	camera_init(t_point3 origin, t_vec3 forward);

void		raytrace(t_camera camera, t_obj **objs, t_mlx_img *img);

#endif
