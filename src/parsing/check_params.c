/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:14:46 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/27 07:13:57 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"
#include "structures.h"

/*Initializing the struct t_obj.*/

t_obj	init_obj(void)
{
	t_obj	obj;

	obj.id = 0;
	obj.fov = 0;
	obj.color = 0;
	// obj.r = 0;
	// obj.g = 0;
	// obj.b = 0;
	obj.lt_ratio = 0;
	obj.pos.x = 0;
	obj.pos.y = 0;
	obj.pos.z = 0;
	obj.ov_pos.x = 0;
	obj.ov_pos.y = 0;
	obj.ov_pos.z = 0;
	obj.sp_diam = 0;
	obj.cy_diam = 0;
	obj.cy_height = 0;
	return (obj);
}

/*The first data indicate the type of the object.*/

void	fill_id(t_obj *obj, char *s)
{
	if (ft_strcmp(s, "A"))
		obj->id = A;
	else if (ft_strcmp(s, "C"))
		obj->id = C;
	else if (ft_strcmp(s, "L"))
		obj->id = L;
	else if (ft_strcmp(s, "pl"))
		obj->id = PL;
	else if (ft_strcmp(s, "sp"))
		obj->id = SP;
	else if (ft_strcmp(s, "cy"))
		obj->id = CY;
	else
		obj->id = -1;
}
