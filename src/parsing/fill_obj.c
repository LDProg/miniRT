/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:49:22 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/27 07:13:16 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"
#include "parsing/parsing.h"
#include "structures.h"

/*Fill the struct if the object is a Sphere.*/

void	fill_sp(t_obj *obj, char **db_tab)
{
	obj->pos.x = ft_atof(db_tab[1]);
	obj->pos.y = ft_atof(db_tab[2]);
	obj->pos.z = ft_atof(db_tab[3]);
	obj->pos.w = 0;
	obj->sp_diam = ft_atof(db_tab[4]);
	obj->color = fill_color(db_tab[5], db_tab[6], db_tab[7]);
	return ;
}

/*Fill the struct if the object is a Plane.*/

void	fill_pl(t_obj *obj, char **db_tab)
{
	obj->pos.x = ft_atof(db_tab[1]);
	obj->pos.y = ft_atof(db_tab[2]);
	obj->pos.z = ft_atof(db_tab[3]);
	obj->pos.w = 0;
	obj->ov_pos.x = ft_atof(db_tab[4]);
	obj->ov_pos.y = ft_atof(db_tab[5]);
	obj->ov_pos.z = ft_atof(db_tab[6]);
	obj->ov_pos.w = 0;
	obj->color = fill_color(db_tab[7], db_tab[8], db_tab[9]);
	return ;
}

/*Fill the struct if the object is a Cylinder.*/

void	fill_cy(t_obj *obj, char **db_tab)
{
	obj->pos.x = ft_atof(db_tab[1]);
	obj->pos.y = ft_atof(db_tab[2]);
	obj->pos.z = ft_atof(db_tab[3]);
	obj->pos.w = 0;
	obj->ov_pos.x = ft_atof(db_tab[4]);
	obj->ov_pos.y = ft_atof(db_tab[5]);
	obj->ov_pos.z = ft_atof(db_tab[6]);
	obj->ov_pos.w = 0;
	obj->cy_diam = ft_atof(db_tab[7]);
	obj->cy_height = ft_atof(db_tab[8]);
	obj->color = fill_color(db_tab[9], db_tab[10], db_tab[11]);
	return ;
}
