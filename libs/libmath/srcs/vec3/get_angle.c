/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_angle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:37:38 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/16 16:44:40 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

double	get_angle(t_vec3 l, t_vec3 n)
{
	double	angle;

	angle = vec3_dot(l, n);
	if (angle < 0)
		return (0);
	return (angle);
}
