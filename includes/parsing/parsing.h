/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:52:51 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/24 20:10:01 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "rt_structures.h"

int			check_args(int ac, char **av);

t_error		parse_file(t_scene *scene, char *filename);

t_error		parse_ambient_light(t_scene *scene, char **trim_line);
t_error		parse_camera(t_scene *scene, char **trim_line);
t_error		parse_diffuse_light(t_scene *scene, char **trim_line);

t_error		parse_sphere(t_object *obj, char **trim_line);
t_error		parse_plane(t_object *obj, char **trim_line);
t_error		parse_cylinder(t_object *obj, char **trim_line);

bool		is_double_in_range(double val, double min, double max);
t_error		parse_color(t_color *color, char *ratio, char *str_rgb);
t_error		parse_point3(t_point3 *point, char *str_point3);
t_error		parse_vec3(t_vec3 *vec, char *str_vec3);

bool		ft_atoi_safe(const char *nptr, int32_t *out);
double		ft_atof_safe(const char *str);
bool		check_atof(double a);
bool		check_tuple(double a, double b, double c);

#endif
