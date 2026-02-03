/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shapes.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:39:27 by ludebion          #+#    #+#             */
/*   Updated: 2026/02/01 08:55:55 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_SHAPES_H
# define INTERSECT_SHAPES_H

# include "rt_structures.h"

bool	intersect_scene_objects(t_dynvec *objs, t_ray ray, t_hit *hit);
bool	hit_cone(t_ray ray, t_cone co, t_hit *hit);
bool	hit_cylinder(t_ray ray, t_cylinder cy, t_hit *hit);
bool	hit_disk(t_ray ray, t_plane pl, t_hit *hit);
bool	hit_plane(t_ray ray, t_plane pl, t_hit *hit);
bool	hit_sphere(t_ray ray, t_sphere sp, t_hit *hit);
bool	intersect_sphere(t_ray ray, t_sphere sp, t_hit *hit);

#endif
