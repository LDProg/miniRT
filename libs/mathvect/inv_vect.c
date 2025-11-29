/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_vect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:14:27 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/29 12:18:26 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"

t_tuple	inv_vect(t_tuple v)
{
	t_tuple	neg_vect;

	init_tuple(&neg_vect);
	if (v.w != 0)
		return (neg_vect);
	neg_vect.x -= v.x;
	neg_vect.y -= v.y;
	neg_vect.z -= v.z;
	return (neg_vect);
}
