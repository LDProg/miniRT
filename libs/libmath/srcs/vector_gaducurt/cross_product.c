/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:45:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/17 13:38:37 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathvect.h"

t_vec3	cross_product(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = (v1.y * v2.z) - (v1.z * v2.y);
	res.y = (v1.z * v2.x) - (v1.x * v2.z);
	res.z = (v1.x * v2.y) - (v1.y * v2.x);
	res.w = 0;
	return (res);
}
