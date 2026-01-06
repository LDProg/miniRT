/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:17:19 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 10:04:57 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "rt_structures.h"

// t_camera	init_camera(t_scene *scene, t_point3 origin, t_vec3 direction, t_dynvec *tab_vec);
t_camera	init_camera(t_scene *scene, t_dynvec *tab_vec, t_obj *cam);

#endif
