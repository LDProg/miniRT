/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:48:43 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/30 11:02:10 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include <stdlib.h>

t_obj	*create_sphere(t_point3 center, double radius, uint32_t rgb)
{
	t_obj		*obj;
	t_sphere	*sphere;

	obj = malloc(sizeof(t_obj));
	if (!obj)
		return (NULL);
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
	{
		free(obj);
		return (NULL);
	}
	sphere->center = center;
	sphere->radius = radius;
	sphere->color.rgb = rgb;
	obj->type = T_SPHERE;
	obj->shape = sphere;
	return (obj);
}
