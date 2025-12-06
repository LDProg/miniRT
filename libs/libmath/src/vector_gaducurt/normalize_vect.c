/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:25:26 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/06 13:43:50 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"

t_tuple	normalize_vect(t_tuple v)
{
	t_tuple	res;
	float	mag;

	init_tuple(&res);
	mag = vect_mag(v);
	res.x = v.x / mag;
	res.y = v.y / mag;
	res.z = v.z / mag;
	return (res);
}
