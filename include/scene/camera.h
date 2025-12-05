/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:17:19 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/03 16:58:49 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "rt_structures.h"

t_camera	init_camera(t_scene *scene, t_point3 origin, t_vec3 direction);

#endif
