/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:49:22 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/12 11:47:51 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "minirt.h"

/*Fill the struct if the object is a Sphere.*/

void	fill_sp(t_obj *obj, char **db_tab)
{
	obj->x = ft_atof(db_tab[1]);
	obj->y = ft_atof(db_tab[2]);
	obj->z = ft_atof(db_tab[3]);
	obj->sp_diam = ft_atof(db_tab[4]);
	obj->r = ft_atoi(db_tab[5]);
	obj->g = ft_atoi(db_tab[6]);
	obj->b = ft_atoi(db_tab[7]);
	return ;
}

/*Fill the struct if the object is a Plane.*/

void	fill_pl(t_obj *obj, char **db_tab)
{
	obj->x = ft_atof(db_tab[1]);
	obj->y = ft_atof(db_tab[2]);
	obj->z = ft_atof(db_tab[3]);
	obj->ov_x = ft_atof(db_tab[4]);
	obj->ov_y = ft_atof(db_tab[5]);
	obj->ov_z = ft_atof(db_tab[6]);
	obj->r = ft_atoi(db_tab[7]);
	obj->g = ft_atoi(db_tab[8]);
	obj->b = ft_atoi(db_tab[9]);
	return ;
}

/*Fill the struct if the object is a Cylinder.*/

void	fill_cy(t_obj *obj, char **db_tab)
{
	obj->x = ft_atof(db_tab[1]);
	obj->y = ft_atof(db_tab[2]);
	obj->z = ft_atof(db_tab[3]);
	obj->ov_x = ft_atof(db_tab[4]);
	obj->ov_y = ft_atof(db_tab[5]);
	obj->ov_z = ft_atof(db_tab[6]);
	obj->cy_diam = ft_atof(db_tab[7]);
	obj->cy_height = ft_atof(db_tab[8]);
	obj->r = ft_atoi(db_tab[9]);
	obj->g = ft_atoi(db_tab[10]);
	obj->b = ft_atoi(db_tab[11]);
	return ;
}
