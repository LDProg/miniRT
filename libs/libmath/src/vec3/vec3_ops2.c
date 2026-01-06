/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_ops2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 08:08:15 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 08:08:46 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath_structures.h"

t_vec3	vec3_negate(t_vec3 v)
{
	t_vec3	res;

	res.x = -v.x;
	res.y = -v.y;
	res.z = -v.z;
	res.w = v.w;
	return (res);
}
