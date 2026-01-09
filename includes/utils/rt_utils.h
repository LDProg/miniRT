/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:29:36 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/09 05:18:59 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include "rt_structures.h"

void		close_program(t_scene *scene, t_error error);

bool		is_valid_color(int r, int g, int b);
uint32_t	get_color(double red, double green, double blue);
uint32_t	graduate_background(double y);
uint32_t	normal_color(t_vec3 p, t_point3 center);

void		print_scene(t_scene *scene, t_dynvec *objs);

bool		solve_quadatric(double a, double b, double c, double *t0);

#endif
