/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 01:20:04 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/01 15:00:08 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_tuple	adding_tuple(t_tuple x, t_tuple y)
{
	return (create_tuple(x.x + y.x, x.y + y.y, x.z + y.z, x.w + y.w));
}

t_tuple	substract_tuple(t_tuple x, t_tuple y)
{
	return (create_tuple(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w));
}

t_tuple	tuple_mul_scalar(t_tuple t, double s)
{
	return (create_vector(t.x * s, t.y * s, t.z * s));
}

t_tuple	tuple_div_scalar(t_tuple t, double s)
{
	return (create_vector(t.x / s, t.y / s, t.z / s));
}

t_tuple	tuple_mul_comp(t_tuple t1, t_tuple t2)
{
	return (create_vector(t1.x * t2.x, t1.y * t2.y, t1.z * t2.z));
}
