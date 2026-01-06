/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:17:19 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 13:50:47 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "rt_structures.h"

// t_camera	init_camera(t_scene *scene, t_point3 origin, t_vec3 direction, t_dynvec *tab_vec);
// t_camera	init_camera(t_scene *scene, t_dynvec *tab_vec, t_obj *cam);
t_camera	camera_init(t_point3 origin, t_vec3 forward);

// void		raytrace(t_camera camera, t_obj_lu **objs, t_mlx_img *img);
void	raytrace(t_camera camera, t_obj_lu **objs, t_mlx_img *img, t_obj *cam);

#endif
