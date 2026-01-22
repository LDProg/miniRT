/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:29:36 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/22 11:54:11 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include "rt_structures.h"

void		close_program(t_scene *scene, t_error error);

bool		is_valid_color(int r, int g, int b);
uint32_t	get_color(double red, double green, double blue);
void		extract_rgb(uint32_t rgb, t_color *color);
uint32_t	graduate_background(double y);
uint32_t	normal_color(t_vec3 p, t_point3 center);
uint32_t	average_pixel_color(uint32_t *pixel_colors, uint32_t samples);
t_color		compute_color(double coef, t_color l_color, t_color o_color);
uint32_t	add_colors(t_color diff, t_color amb);

void		print_scene(t_scene *scene, t_dynvec *objs);

bool		solve_quadatric(double a, double b, double c, double *t0);

#endif
