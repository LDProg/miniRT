/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_two_vect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:38:03 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/06 13:44:00 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"

t_tuple	sub_two_vect(t_tuple v1, t_tuple v2)
{
	t_tuple	res;
	
	init_tuple(&res);
	if (v1.w != 0 || v2.w != 0)
		return (res);
	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	res.w = v1.w - v2.w;
	return (res);
}
