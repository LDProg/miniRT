/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_rotate_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:32:41 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/06 13:43:10 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"
#include <math.h>
#include <stdio.h>

t_tuple	all_rotate_matrix(t_tuple t, float alpha_x, float alpha_y, float alpha_z)
{
	t_tuple	res;

	res = t;
	res = rotate_x(res, alpha_x);
	res = rotate_y(res, alpha_y);
	res = rotate_z(res, alpha_z);
	return (res);
}
