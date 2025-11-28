/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vect_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:56:28 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/28 16:55:29 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"

t_tuple	add_vect_point(t_tuple vector, t_tuple point)
{
	t_tuple	res;
	
	res.x = vector.x + point.x;
	res.y = vector.y + point.y;
	res.z = vector.z + point.z;
	res.w = vector.w + point.w;
	return (res);
}
