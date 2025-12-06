/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:43:56 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/06 13:43:54 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"

t_tuple	scalar_mult(t_tuple v, int	factor)
{
	t_tuple	res;

	init_tuple(&res);
	res.x = v.x * factor;
	res.y = v.y * factor;
	res.z = v.z * factor;
	res.w = v.w * factor;
	return (res);
}
