/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:28:12 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/23 16:12:52 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene/mlx_window.h"

static char	*get_error_message(t_error error)
{
	if (error == ERR_MALLOC)
		return ("Malloc error.\n");
	else if (error == ERR_IDENTIFIER)
		return ("Identifier error.\n\tAvailable A C L and sp pl cy.\n");
	else if (error == ERR_MISSING_OBJ)
		return ("Missing necessary objects.\n");
	else if (error == ERR_CAMERA)
		return ("Camera error:\n\tInvalid parameters or multiple cameras.\n");
	else if (error == ERR_LIGHT)
		return ("Light error:\n\tInvalid parameters or multiple lights.\n");
	else if (error == ERR_FORMAT)
		return ("Object parameters format error.\n");
	else if (error == ERR_COLOR)
		return ("Color parameters error.\n");
	else if (error == ERR_RANGE)
		return ("Ratio range parameter error.\n");
	else if (error == ERR_NORMAL)
		return ("Normal parameters error.\n");
	else if (error == ERR_DIAMETER)
		return ("Diameter parameter error.\n");
	else if (error == ERR_TUPLE)
		return ("Point parameters error.\n");
	else if (error == ERR_MLX)
		return ("Mlx error.\n");
	return ("Failure.\n");
}

void	close_program(t_scene *scene, t_error error)
{
	ft_free_vector(scene->objs);
	mlx_clear(scene);
	if (error != ERR_NONE)
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		ft_putstr_fd(get_error_message(error), STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd("Program close successfully.\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
