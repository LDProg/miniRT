/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:15:22 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/19 03:02:12 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

double	vec3_dot(t_vec3 v, t_vec3 w)
{
	return ((v.x * w.x) + (v.y * w.y) + (v.z * w.z));
}

t_tuple	vec3_cross(t_vec3 v, t_vec3 w)
{
	return (vec3_new((v.y * w.z) - (v.z * w.y), (v.z * w.x) - (v.x * w.z), (v.x
				* w.y) - (v.y * w.x)));
}
