/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:23:20 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/13 20:11:40 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"
#include "libft.h"

t_error	parse_ambient_light(t_scene *scene, char **trim_line)
{
	t_error	err;

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

	if (!trim_line[1] || !trim_line[2] || !trim_line[3] || trim_line[4])
		return (ERR_FORMAT);
	err = parse_point3(&scene->camera.origin, trim_line[1]);
	if (err != ERR_NONE)
		return (err);
	err = parse_vec3(&scene->camera.forward, trim_line[2]);
	if (err != ERR_NONE)
		return (err);
	scene->camera.fov = ft_atoi_safe(trim_line[3]);
	// need to protect?
	if (scene->camera.fov < 0 || scene->camera.fov > 180)
		return (ERR_CAMERA);
	scene->has_camera = true;
	return (ERR_NONE);
}

t_error	parse_diffuse_light(t_scene *scene, char **trim_line)
{
	t_error	err;

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

bool	digit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_rgb(char *r, char *g, char *b)
{
	if (!digit_str(r) || !digit_str(g) || !digit_str(b))
		return (false);
	return (true);
}
