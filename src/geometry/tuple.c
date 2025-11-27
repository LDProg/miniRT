/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:35:39 by ludebion          #+#    #+#             */
/*   Updated: 2025/11/27 10:50:40 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include <stdbool.h>

t_tuple	create_tuple(double x, double y, double z, double w)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return (t);
}

t_tuple	create_point(double x, double y, double z)
{
	return (create_tuple(x, y, z, 1.0));
}

t_tuple	create_vector(double x, double y, double z)
{
	return (create_tuple(x, y, z, 0.0));
}

bool	is_point(t_tuple t)
{
	return (t.w == 1.0);
}

bool	is_vector(t_tuple t)
{
	return (t.w == 0.0);
}
