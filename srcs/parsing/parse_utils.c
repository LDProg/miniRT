/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:00:39 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/14 11:05:05 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing/parsing.h"
#include "utils/rt_utils.h"

bool	is_double_in_range(double val, double min, double max)
{
	return (val >= min && val <= max);
}

t_error	parse_color(t_color *color, char *ratio, char *str_rgb)
{
	char	**rgb;

	color->ratio = ft_atof_safe(ratio);
	if (!check_atof(color->ratio) || !is_double_in_range(color->ratio, 0.0,
			1.0))
		return (ERR_RANGE);
	rgb = ft_split(str_rgb, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		free_strs(rgb);
		return (ERR_COLOR);
	}
	if (!check_rgb(rgb[0], rgb[1], rgb[2]))
		return (ERR_COLOR);
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	free_strs(rgb);
	if (!is_valid_color(color->r, color->g, color->b))
		return (ERR_COLOR);
	color->rgb = get_color(color->r, color->g, color->b);
	return (ERR_NONE);
}

t_error	parse_point3(t_point3 *point, char *str_point3)
{
	char	**coords;

	coords = ft_split(str_point3, ',');
	if (!coords || !coords[0] || !coords[1] || !coords[2] || coords[3])
	{
		free_strs(coords);
		return (ERR_TUPLE);
	}
	*point = point3_new(ft_atof_safe(coords[0]), ft_atof_safe(coords[1]),
			ft_atof_safe(coords[2]));
	free_strs(coords);
	if (!check_tuple(point->x, point->y, point->z))
		return (ERR_TUPLE);
	return (ERR_NONE);
}

t_error	parse_vec3(t_vec3 *vec, char *str_vec3)
{
	char	**coords;

	coords = ft_split(str_vec3, ',');
	if (!coords || !coords[0] || !coords[1] || !coords[2] || coords[3])
	{
		free_strs(coords);
		return (ERR_TUPLE);
	}
	vec->x = ft_atof_safe(coords[0]);
	vec->y = ft_atof_safe(coords[1]);
	vec->z = ft_atof_safe(coords[2]);
	free_strs(coords);
	if (!check_tuple(vec->x, vec->y, vec->z))
		return (ERR_TUPLE);
	if (!is_normalized_vec(*vec))
		return (ERR_NORMAL);
	return (ERR_NONE);
}
