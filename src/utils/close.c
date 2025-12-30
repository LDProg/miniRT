/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:28:12 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/30 03:24:45 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt_structures.h"
#include "scene/mlx_window.h"
#include <stdlib.h>

void	close_program(t_scene *scene, char *message, bool is_format,
		bool is_error)
{
	mlx_clear(scene);
	if (is_format)
		ft_putstr_fd("\n\tPlease execute\n\t", STDOUT_FILENO);
	else
		ft_putstr_fd(message, STDERR_FILENO);
	if (is_error)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
