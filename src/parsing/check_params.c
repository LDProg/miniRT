/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:14:46 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/18 17:53:41 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"
#include "structures.h"

/*Initializing the struct t_obj.*/

t_obj	init_obj(void)
{
	t_obj	obj;

	obj.type = 0;
	obj.fov = 0;
	obj.color.r = 0;
	obj.color.g = 0;
	obj.color.b = 0;
	obj.lt_ratio = 0;
	obj.pos.x = 0;
	obj.pos.y = 0;
	obj.pos.z = 0;
	obj.norm_v.x = 0;
	obj.norm_v.y = 0;
	obj.norm_v.z = 0;
	obj.sp_diam = 0;
	obj.cy_diam = 0;
	obj.cy_height = 0;
	return (obj);
}

/*The first data indicate the type of the object.*/

void	fill_type(t_obj *obj, char *s)
{
	if (ft_strcmp(s, "A"))
		obj->type = A;
	else if (ft_strcmp(s, "C"))
		obj->type = C;
	else if (ft_strcmp(s, "L"))
		obj->type = L;
	else if (ft_strcmp(s, "pl"))
		obj->type = PL;
	else if (ft_strcmp(s, "sp"))
		obj->type = SP;
	else if (ft_strcmp(s, "cy"))
		obj->type = CY;
	else
		obj->type = -1;
}
