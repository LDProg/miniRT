/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_vect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:14:27 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/29 12:35:34 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"

t_tuple	inv_tup(t_tuple v)
{
	t_tuple	neg_tup;

	init_tuple(&neg_tup);
	// if (v.w != 0)
	// 	return (neg_tup);
	neg_tup.x -= v.x;
	neg_tup.y -= v.y;
	neg_tup.z -= v.z;
	neg_tup.w -= v.w;
	return (neg_tup);
}
