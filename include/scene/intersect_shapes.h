/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shapes.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:39:27 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/07 15:14:11 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_SHAPES_H
# define INTERSECT_SHAPES_H

# include "rt_structures.h"

// bool	hit_cylinder(t_ray ray, t_cylinder *cy, t_hit *hit);
// bool	hit_plane(t_ray ray, t_plane *pl, t_hit *hit);
// bool	hit_sphere(t_ray ray, t_sphere *sp, t_hit *hit);
bool	hit_plane(t_ray *ray, t_obj *pl, t_obj *d_light, t_obj *a_light);
bool	hit_cylinder(t_ray *ray, t_obj *cy, t_obj *d_light, t_obj *a_light);

#endif
