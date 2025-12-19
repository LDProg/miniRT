/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_trsf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 06:42:34 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/19 01:22:21 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include <math.h>

t_mat4	mat4_translation(double x, double y, double z)
{
	t_mat4	m;

	m = mat4_identity();
	m.t.x = x;
	m.t.y = y;
	m.t.z = z;
	return (m);
}

t_mat4	mat4_scale(double sx, double sy, double sz)
{
	t_mat4	m;

	m = mat4_identity();
	m.x.x = sx;
	m.y.y = sy;
	m.z.z = sz;
	return (m);
}

t_mat4	mat4_rotation_x(double angle)
{
	t_mat4	m;
	double	c;
	double	s;

	c = cos(angle);
	s = sin(angle);
	m = mat4_identity();
	m.y.y = c;
	m.y.z = s;
	m.z.y = -s;
	m.z.z = c;
	return (m);
}

t_mat4	mat4_rotation_y(double angle)
{
	t_mat4	m;
	double	c;
	double	s;

	c = cos(angle);
	s = sin(angle);
	m = mat4_identity();
	m.x.x = c;
	m.x.z = -s;
	m.z.x = s;
	m.z.z = c;
	return (m);
}

t_mat4	mat4_rotation_z(double angle)
{
	t_mat4	m;
	double	c;
	double	s;

	c = cos(angle);
	s = sin(angle);
	m = mat4_identity();
	m.x.x = c;
	m.x.y = s;
	m.y.x = -s;
	m.y.y = c;
	return (m);
}
