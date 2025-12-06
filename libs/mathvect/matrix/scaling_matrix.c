/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:32:34 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/06 13:43:35 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"

t_tuple	scaling_matrix(t_tuple t, float sx, float sy, float sz)
{
	t_tuple res;

    init_tuple(&res);
    res.x = t.x * sx;
    res.y = t.y * sy;
    res.z = t.z * sz;
    res.w = t.w;
    return (res);
}