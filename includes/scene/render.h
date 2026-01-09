/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:17:19 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/08 16:21:42 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "rt_structures.h"

void	camera_init(t_camera *camera);

void	raytrace(t_camera camera, t_dynvec *objs, t_mlx_img *img);

#endif
