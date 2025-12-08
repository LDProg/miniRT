/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_mag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:02:34 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/08 10:53:31 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathvect.h"
#include <stdio.h>

double	vect_mag(t_tuple v)
{
	double	res;

	res = sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2));
	return (res);
}
