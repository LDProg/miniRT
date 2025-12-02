/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:15:22 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/02 01:36:10 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"
#include <math.h>

double	vector_magnitude(t_tuple v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

t_tuple	vector_normalize(t_tuple v)
{
	return (tuple_div_scalar(v, vector_magnitude(v)));
}
