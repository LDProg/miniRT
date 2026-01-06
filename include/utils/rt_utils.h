/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:29:36 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 11:17:54 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include "rt_structures.h"

uint32_t	graduate_background(double y);
uint32_t	normal_color(t_vec3 p, t_point3 center);

void		close_program(t_scene *scene, char *message, bool is_format,
				bool is_error);

bool		solve_quadatric(double a, double b, double c, double *t0);

#endif
