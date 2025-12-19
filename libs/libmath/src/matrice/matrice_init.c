/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 06:22:06 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/19 00:51:26 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath_structures.h"

t_mat4	mat4_identity(void)
{
	return ((t_mat4){{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});
}

t_mat4	mat4_zero(void)
{
	return ((t_mat4){{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}});
}

t_mat4	mat4_new(t_tuple x, t_tuple y, t_tuple z, t_tuple t)
{
	t_mat4	m;

	m.x = x;
	m.y = y;
	m.z = z;
	m.t = t;
	return (m);
}
