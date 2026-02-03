/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:10:27 by ludebion          #+#    #+#             */
/*   Updated: 2026/02/03 03:37:47 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"
#include <math.h>

t_error	parse_sphere(t_object *obj, char **trim_line)
{
	t_error	err;

	err = ERR_NONE;
	if (!trim_line[1] || !trim_line[2] || !trim_line[3] || trim_line[4])
		return (ERR_FORMAT);
	obj->type = T_SPHERE;
	err = parse_point3(&obj->shape.sphere.center, trim_line[1]);
	if (err != ERR_NONE)
		return (ERR_TUPLE);
	obj->shape.sphere.radius = ft_atof_safe(trim_line[2]) / 2.0;
	if (obj->shape.sphere.radius <= 0 || !check_atof(obj->shape.sphere.radius))
		return (ERR_DIAMETER);
	err = parse_color(&obj->shape.sphere.color, "1", trim_line[3]);
	if (err != ERR_NONE)
		return (ERR_COLOR);
	return (ERR_NONE);
}

t_error	parse_plane(t_object *obj, char **trim_line)
{
	t_error	err;

	err = ERR_NONE;
	if (!trim_line[1] || !trim_line[2] || !trim_line[3] || trim_line[4])
		return (ERR_FORMAT);
	obj->type = T_PLANE;
	err = parse_point3(&obj->shape.plane.center, trim_line[1]);
	if (err != ERR_NONE)
		return (ERR_TUPLE);
	err = parse_vec3(&obj->shape.plane.normal, trim_line[2]);
	if (err != ERR_NONE)
		return (ERR_NORMAL);
	obj->shape.plane.normal = vec3_normalize(obj->shape.plane.normal);
	err = parse_color(&obj->shape.plane.color, "1", trim_line[3]);
	if (err != ERR_NONE)
		return (ERR_COLOR);
	return (ERR_NONE);
}

t_error	parse_cylinder(t_object *obj, char **trim_line)
{
	t_error	err;

	err = ERR_NONE;
	if (!trim_line[1] || !trim_line[2] || !trim_line[3] || !trim_line[4]
		|| !trim_line[5] || trim_line[6])
		return (ERR_FORMAT);
	obj->type = T_CYLINDER;
	err = parse_point3(&obj->shape.cylinder.center, trim_line[1]);
	if (err != ERR_NONE)
		return (ERR_TUPLE);
	err = parse_vec3(&obj->shape.cylinder.axis, trim_line[2]);
	if (err != ERR_NONE)
		return (ERR_NORMAL);
	obj->shape.cylinder.axis = vec3_normalize(obj->shape.cylinder.axis);
	obj->shape.cylinder.radius = ft_atof_safe(trim_line[3]);
	obj->shape.cylinder.height = ft_atof_safe(trim_line[4]);
	if (obj->shape.cylinder.radius <= 0 || obj->shape.cylinder.height <= 0
		|| !check_atof(obj->shape.cylinder.radius)
		|| !check_atof(obj->shape.cylinder.height))
		return (ERR_DIAMETER);
	obj->shape.cylinder.radius = obj->shape.cylinder.radius * 0.5;
	err = parse_color(&obj->shape.cylinder.color, "1", trim_line[5]);
	if (err != ERR_NONE)
		return (ERR_COLOR);
	return (ERR_NONE);
}

t_error	parse_cone(t_object *obj, char **trim_line)
{
	t_error	err;

	err = ERR_NONE;
	if (!trim_line[1] || !trim_line[2] || !trim_line[3] || !trim_line[4]
		|| !trim_line[5] || trim_line[6])
		return (ERR_FORMAT);
	obj->type = T_CONE;
	err = parse_point3(&obj->shape.cone.center, trim_line[1]);
	if (err != ERR_NONE)
		return (ERR_TUPLE);
	err = parse_vec3(&obj->shape.cone.axis, trim_line[2]);
	if (err != ERR_NONE)
		return (ERR_NORMAL);
	obj->shape.cone.axis = vec3_normalize(obj->shape.cone.axis);
	obj->shape.cone.angle = ft_atof_safe(trim_line[3]);
	obj->shape.cone.height = ft_atof_safe(trim_line[4]);
	if (obj->shape.cone.angle <= 0 || obj->shape.cone.angle >= 90
		|| obj->shape.cone.height <= 0 || !check_atof(obj->shape.cone.angle)
		|| !check_atof(obj->shape.cone.height))
		return (ERR_FORMAT);
	obj->shape.cone.angle = obj->shape.cone.angle * (M_PI / 180.0);
	err = parse_color(&obj->shape.cone.color, "1", trim_line[5]);
	if (err != ERR_NONE)
		return (ERR_COLOR);
	return (ERR_NONE);
}
