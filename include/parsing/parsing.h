/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:52:51 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 06:30:53 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "rt_structures.h"

t_obj	*create_plane(t_point3 center, t_vec3 normal, uint32_t rgb);
t_obj	*create_sphere(t_point3 center, double radius, uint32_t rgb);
t_obj	*create_cylinder(t_point3 center, t_point3 vz, double radius,
			double height, uint32_t rgb);

#endif
