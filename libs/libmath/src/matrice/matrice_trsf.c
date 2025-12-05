/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_trsf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 06:42:34 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/05 06:49:37 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include <math.h>

t_mat4	mat4_translation(double x, double y, double z)
{
	t_mat4	m;

	m = mat4_identity();
	m.m[0][3] = x;
	m.m[1][3] = y;
	m.m[2][3] = z;
	return (m);
}

t_mat4	mat4_scale(double x, double y, double z)
{
	t_mat4	m;

	m = mat4_identity();
	m.m[0][0] = x;
	m.m[1][1] = y;
	m.m[2][2] = z;
	return (m);
}

t_mat4	mat4_rotation_x(double angle)
{
	t_mat4	m;
	double	c;
	double	s;

	m = mat4_identity();
	c = cos(angle);
	s = sin(angle);
	m.m[1][1] = c;
	m.m[1][2] = -s;
	m.m[2][1] = s;
	m.m[2][2] = c;
	return (m);
}

t_mat4	mat4_rotation_y(double angle)
{
	t_mat4	m;
	double	c;
	double	s;

	m = mat4_identity();
	c = cos(angle);
	s = sin(angle);
	m.m[0][0] = c;
	m.m[0][2] = s;
	m.m[2][0] = -s;
	m.m[2][2] = c;
	return (m);
}

t_mat4	mat4_rotation_z(double angle)
{
	t_mat4	m;
	double	c;
	double	s;

	m = mat4_identity();
	c = cos(angle);
	s = sin(angle);
	m.m[0][0] = c;
	m.m[0][1] = -s;
	m.m[1][0] = s;
	m.m[1][1] = c;
	return (m);
}
