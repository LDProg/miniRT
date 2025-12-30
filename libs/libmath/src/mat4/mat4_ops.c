/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 06:23:41 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/30 03:40:13 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_tuple	mat4_mul_point(t_mat4 m, t_tuple p)
{
	t_tuple	result;

	result.x = m.x.x * p.x + m.y.x * p.y + m.z.x * p.z + m.t.x;
	result.y = m.x.y * p.x + m.y.y * p.y + m.z.y * p.z + m.t.y;
	result.z = m.x.z * p.x + m.y.z * p.y + m.z.z * p.z + m.t.z;
	result.w = 1.0;
	return (result);
}

t_tuple	mat4_mul_vector(t_mat4 m, t_tuple v)
{
	t_tuple	result;

	result.x = m.x.x * v.x + m.y.x * v.y + m.z.x * v.z;
	result.y = m.x.y * v.x + m.y.y * v.y + m.z.y * v.z;
	result.z = m.x.z * v.x + m.y.z * v.y + m.z.z * v.z;
	result.w = 0.0;
	return (result);
}

t_mat4	mat4_mul(t_mat4 a, t_mat4 b)
{
	t_mat4	r;

	r.x.x = a.x.x * b.x.x + a.y.x * b.x.y + a.z.x * b.x.z + a.t.x * b.x.w;
	r.x.y = a.x.y * b.x.x + a.y.y * b.x.y + a.z.y * b.x.z + a.t.y * b.x.w;
	r.x.z = a.x.z * b.x.x + a.y.z * b.x.y + a.z.z * b.x.z + a.t.z * b.x.w;
	r.x.w = a.x.w * b.x.x + a.y.w * b.x.y + a.z.w * b.x.z + a.t.w * b.x.w;
	r.y.x = a.x.x * b.y.x + a.y.x * b.y.y + a.z.x * b.y.z + a.t.x * b.y.w;
	r.y.y = a.x.y * b.y.x + a.y.y * b.y.y + a.z.y * b.y.z + a.t.y * b.y.w;
	r.y.z = a.x.z * b.y.x + a.y.z * b.y.y + a.z.z * b.y.z + a.t.z * b.y.w;
	r.y.w = a.x.w * b.y.x + a.y.w * b.y.y + a.z.w * b.y.z + a.t.w * b.y.w;
	r.z.x = a.x.x * b.z.x + a.y.x * b.z.y + a.z.x * b.z.z + a.t.x * b.z.w;
	r.z.y = a.x.y * b.z.x + a.y.y * b.z.y + a.z.y * b.z.z + a.t.y * b.z.w;
	r.z.z = a.x.z * b.z.x + a.y.z * b.z.y + a.z.z * b.z.z + a.t.z * b.z.w;
	r.z.w = a.x.w * b.z.x + a.y.w * b.z.y + a.z.w * b.z.z + a.t.w * b.z.w;
	r.t.x = a.x.x * b.t.x + a.y.x * b.t.y + a.z.x * b.t.z + a.t.x * b.t.w;
	r.t.y = a.x.y * b.t.x + a.y.y * b.t.y + a.z.y * b.t.z + a.t.y * b.t.w;
	r.t.z = a.x.z * b.t.x + a.y.z * b.t.y + a.z.z * b.t.z + a.t.z * b.t.w;
	r.t.w = a.x.w * b.t.x + a.y.w * b.t.y + a.z.w * b.t.z + a.t.w * b.t.w;
	return (r);
}

t_mat4	mat4_transpose(t_mat4 m)
{
	t_mat4	result;

	result.x.x = m.x.x;
	result.x.y = m.y.x;
	result.x.z = m.z.x;
	result.x.w = m.t.x;
	result.y.x = m.x.y;
	result.y.y = m.y.y;
	result.y.z = m.z.y;
	result.y.w = m.t.y;
	result.z.x = m.x.z;
	result.z.y = m.y.z;
	result.z.z = m.z.z;
	result.z.w = m.t.z;
	result.t.x = m.x.w;
	result.t.y = m.y.w;
	result.t.z = m.z.w;
	result.t.w = m.t.w;
	return (result);
}
