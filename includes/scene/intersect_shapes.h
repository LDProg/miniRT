/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shapes.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:39:27 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/08 15:58:30 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_SHAPES_H
# define INTERSECT_SHAPES_H

# include "rt_structures.h"

bool	hit_cylinder(t_ray ray, t_cylinder cy, t_hit *hit);
bool	hit_plane(t_ray ray, t_plane pl, t_hit *hit);
bool	hit_sphere(t_ray ray, t_sphere sp, t_hit *hit);

#endif
