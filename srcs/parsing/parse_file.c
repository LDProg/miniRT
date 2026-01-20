/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:15:53 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/14 15:42:27 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "mylib.h"
#include "libft.h"
#include "parsing/parsing.h"

static t_error	parse_and_add_object(t_dynvec *objs, char **trim_line)
{
	t_object	obj;
	t_error		err;

	if (ft_strncmp(trim_line[0], "sp", 3) == 0)
		err = parse_sphere(&obj, trim_line);
	else if (ft_strncmp(trim_line[0], "pl", 3) == 0)
		err = parse_plane(&obj, trim_line);
	else
		err = parse_cylinder(&obj, trim_line);
	if (err != ERR_NONE)
		return (err);
	if (!ft_vector_addone(objs, &obj))
		return (ERR_MALLOC);
	return (ERR_NONE);
}

static t_error	parse_line(t_scene *scene, char *line)
{
	char	**trim_line;
	t_error	err;

	trim_line = split_charset(line, " \t\n");
	if (!trim_line || !trim_line[0])
	{
		free_strs(trim_line);
		return (ERR_NONE);
	}
	err = ERR_NONE;
	if (ft_strncmp(trim_line[0], "A", 2) == 0)
		err = parse_ambient_light(scene, trim_line);
	else if (ft_strncmp(trim_line[0], "C", 2) == 0)
		err = parse_camera(scene, trim_line);
	else if (ft_strncmp(trim_line[0], "L", 2) == 0)
		err = parse_diffuse_light(scene, trim_line);
	else if (ft_strncmp(trim_line[0], "sp", 3) == 0 || ft_strncmp(trim_line[0],
			"pl", 3) == 0 || ft_strncmp(trim_line[0], "cy", 3) == 0)
		err = parse_and_add_object(scene->objs, trim_line);
	else
		err = ERR_IDENTIFIER;
	free_strs(trim_line);
	return (err);
}

t_error	parse_file(t_scene *scene, char *filename)
{
	t_error	err;
	int32_t	fd;
	char	*line;

	err = ERR_NONE;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERR_OPEN);
	line = get_next_line(fd);
	while (line)
	{
		err = parse_line(scene, line);
		free(line);
		if (err != ERR_NONE)
		{
			close(fd);
			return (err);
		}
		line = get_next_line(fd);
	}
	close(fd);
	if (!scene->has_ambient || !scene->has_camera || !scene->has_diffuse_light)
		err = ERR_MISSING_OBJ;
	return (err);
}
