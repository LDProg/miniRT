/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:35:39 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/08 11:02:43 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath_structures.h"
#include <stdbool.h>

t_tuple	tuple_new(double x, double y, double z, double w)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return (t);
}

t_point3	point3_new(double x, double y, double z)
{
	return (tuple_new(x, y, z, 1.0));
}

t_vec3	vec3_new(double x, double y, double z)
{
	return (tuple_new(x, y, z, 0.0));
}
