/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_mag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:02:34 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/06 13:44:02 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathvect.h"
#include <stdio.h>

float	vect_mag(t_tuple v)
{
	float	res;

	res = sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2));
	return (res);
}
