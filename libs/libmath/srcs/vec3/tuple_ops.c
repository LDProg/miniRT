/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 01:20:04 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/30 03:37:26 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_tuple	adding_tuple(t_tuple t1, t_tuple t2)
{
	return (tuple_new(t1.x + t2.x, t1.y + t2.y, t1.z + t2.z, t1.w + t2.w));
}

t_tuple	substract_tuple(t_tuple t1, t_tuple t2)
{
	return (tuple_new(t1.x - t2.x, t1.y - t2.y, t1.z - t2.z, t1.w - t2.w));
}

t_tuple	tuple_mul_scalar(t_tuple t, double s)
{
	return (tuple_new(t.x * s, t.y * s, t.z * s, t.w));
}

t_tuple	tuple_div_scalar(t_tuple t, double s)
{
	return (tuple_new(t.x / s, t.y / s, t.z / s, t.w));
}

t_tuple	tuple_mul_comp(t_tuple t1, t_tuple t2)
{
	return (vec3_new(t1.x * t2.x, t1.y * t2.y, t1.z * t2.z));
}
