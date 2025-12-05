/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:09:05 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/03 15:31:16 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"
#include <math.h>
#include <stdio.h>

/*
Rotation matrix along the y-axis = 	{{cos(teta),  0, sin(teta)},
						 			 {0, 		  1, 0		  }
						 			 {-sin(teta), 0, cos(teta)}}
*/

t_tuple	rotate_y(t_tuple t, float alpha)
{
	t_tuple	res;
	float	rad_alpha;

	rad_alpha = (M_PI / 180) * alpha;
	init_tuple(&res);
	res.x = cosf(rad_alpha) * t.x + sinf(rad_alpha) * t.z;
	res.y = t.y;
	res.z = -sinf(rad_alpha) * t.x + cosf(rad_alpha) * t.z;
	res.w = t.w;
	printf("res.x = %g\nres.y = %g\nres.z = %g\n\n", res.x, res.y, res.z);
	return (res);
}