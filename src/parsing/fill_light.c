/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:49:13 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/12 11:48:03 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "minirt.h"

/*Fill the struct if the object is an Ambient lighting.*/

void	fill_a(t_obj *obj, char **db_tab)
{
	obj->lt_ratio = ft_atof(db_tab[1]);
	obj->r = ft_atoi(db_tab[2]);
	obj->g = ft_atoi(db_tab[3]);
	obj->b = ft_atoi(db_tab[4]);
	return ;
}

/*Fill the struct if the object is a Camera.*/

void	fill_c(t_obj *obj, char **db_tab)
{
	obj->x = ft_atof(db_tab[1]);
	obj->y = ft_atof(db_tab[2]);
	obj->z = ft_atof(db_tab[3]);
	obj->ov_x = ft_atof(db_tab[4]);
	obj->ov_y = ft_atof(db_tab[5]);
	obj->ov_z = ft_atof(db_tab[6]);
	obj->fov = ft_atoi(db_tab[7]);
	return ;
}

/*Fill the struct if the object is a Light.*/

void	fill_l(t_obj *obj, char **db_tab)
{
	obj->x = ft_atof(db_tab[1]);
	obj->y = ft_atof(db_tab[2]);
	obj->z = ft_atof(db_tab[3]);
	obj->lt_ratio = ft_atof(db_tab[4]);
	obj->r = ft_atoi(db_tab[5]);
	obj->g = ft_atoi(db_tab[6]);
	obj->b = ft_atoi(db_tab[7]);
	return ;
}
