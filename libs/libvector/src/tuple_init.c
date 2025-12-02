/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:35:39 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/02 04:50:18 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_structures.h"
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
