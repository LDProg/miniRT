/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_two_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:22:32 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/28 17:48:01 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"

t_tuple	sub_two_points(t_tuple p1, t_tuple p2)
{
	t_tuple	res;

	init_tuple(&res);
	if (p1.w != 1 || p2.w != 1)
		return (res);
	res.x = p1.x - p2.x;
	res.y = p1.y - p2.y;
	res.z = p1.z - p2.z;
	res.w = p1.w - p2.w;
	return (res);
}
