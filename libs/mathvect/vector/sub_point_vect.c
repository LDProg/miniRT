/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_point_vect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:25:56 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/28 17:29:12 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"

t_tuple	sub_point_vect(t_tuple p, t_tuple v)
{
	t_tuple	res;

	init_tuple(&res);
	if (p.w != 1)
		return (res);
	if (v.w != 0)
		return (res);
	res.x = p.x - v.x;
	res.y = p.y - v.y;
	res.z = p.z - v.z;
	res.w = p.w - v.w;
	return (res);
}
