/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:49:42 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/01 16:58:42 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"
#include "matrixlib.h"

/*
Translation matrix = 	{{1, 0, 0, trx},
						 {0, 1, 0, try},
						 {0, 0, 1, trz},
						 {0, 0, 0, 1}}
*/

t_tuple	translate_matrix(t_tuple t, float trx, float try, float trz)
{
	t_tuple	res;
	
	init_tuple(&res);
	if (t.w != 0 && t.w != 1)
		return (res);
	res.x = t.x * trx;
	res.y = t.y * try;
	res.z = t.z * trz;
	return (res);
}
