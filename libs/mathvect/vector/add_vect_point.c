/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vect_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:56:28 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/05 14:51:11 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"

t_tuple	add_vect_point(t_tuple v, t_tuple p)
{
	t_tuple	res;

	init_tuple(&res);
	if (v.w != 0)
		return (res);
	if (p.w != 1)
		return (res);
	res.x = v.x + p.x;
	res.y = v.y + p.y;
	res.z = v.z + p.z;
	res.w = v.w + p.w;
	return (res);
}
