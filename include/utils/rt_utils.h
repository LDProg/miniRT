/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:29:36 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/02 05:56:24 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include "rt_structures.h"

void	close_program(t_scene *scene, char *message, bool is_format,
			bool is_error);

#endif
