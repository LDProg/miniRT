/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:07:41 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/06 13:43:33 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"
#include <math.h>
#include <stdio.h>

/*
Rotation matrix along the z-axis = 	{{cos(teta),  -sin(teta), 0},
						 			 {sin(teta),  cos(teta),  0}
						 			 {0, 		  0, 		  1}}
*/

t_tuple	rotate_z(t_tuple t, float alpha)
{
	t_tuple	res;
	float	rad_alpha;

	rad_alpha = (M_PI / 180) * alpha;
	init_tuple(&res);
	res.x = cosf(rad_alpha) * t.x - sinf(rad_alpha) * t.y;
	res.y = sinf(rad_alpha) * t.x + cosf(rad_alpha) * t.y;
	res.z = t.z;
	res.w = t.w;
	printf("res.x = %g\nres.y = %g\nres.z = %g\n\n", res.x, res.y, res.z);
	return (res);
}
