/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:23:20 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/24 18:01:58 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing/parsing.h"
#include <stdio.h>

t_error	parse_ambient_light(t_scene *scene, char **trim_line)
{
	t_error	err;

	if (scene->has_ambient == true)
		return (ERR_LIGHT);
	if (!trim_line[1] || !trim_line[2] || trim_line[3])
		return (ERR_FORMAT);
	err = parse_color(&scene->ambient, trim_line[1], trim_line[2]);
	if (err != ERR_NONE)
		return (err);
	scene->has_ambient = true;
	return (ERR_NONE);
}

t_error	parse_camera(t_scene *scene, char **trim_line)
{
	t_error	err;

	if (scene->has_camera == true)
		return (ERR_CAMERA);
	if (!trim_line[1] || !trim_line[2] || !trim_line[3] || trim_line[4])
		return (ERR_FORMAT);
	err = parse_point3(&scene->camera.origin, trim_line[1]);
	if (err != ERR_NONE)
		return (err);
	err = parse_vec3(&scene->camera.forward, trim_line[2]);
	if (err != ERR_NONE)
		return (err);
	if (!ft_atoi_safe(trim_line[3], &scene->camera.fov) || scene->camera.fov < 0
		|| scene->camera.fov > 180)
		return (ERR_CAMERA);
	scene->has_camera = true;
	return (ERR_NONE);
}

t_error	parse_diffuse_light(t_scene *scene, char **trim_line)
{
	t_error	err;

	if (scene->has_diffuse_light == true)
		return (ERR_LIGHT);
	if (!trim_line[1] || !trim_line[2] || !trim_line[3] || trim_line[4])
		return (ERR_FORMAT);
	err = parse_point3(&scene->light.position, trim_line[1]);
	if (err != ERR_NONE)
		return (err);
	err = parse_color(&scene->light.color, trim_line[2], trim_line[3]);
	if (err != ERR_NONE)
		return (err);
	scene->has_diffuse_light = true;
	return (ERR_NONE);
}
