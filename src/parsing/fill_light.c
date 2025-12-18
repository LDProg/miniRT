/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:49:13 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/18 17:59:59 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mylib.h"
#include "parsing/parsing.h"
#include <stdio.h>
#include "minirt.h"


/*Fill the struct if the object is an Ambient lighting.*/

void	fill_a(t_obj *obj, char **db_tab)
{
	obj->lt_ratio = ft_atof(db_tab[1]);
	obj->color.rgb = fill_color(db_tab[2], db_tab[3], db_tab[4]);
	obj->color.r = ft_atof(db_tab[2]);
	obj->color.g = ft_atof(db_tab[3]);
	obj->color.b = ft_atof(db_tab[4]);
	return ;
}

/*Fill the struct if the object is a Camera.*/

void	fill_c(t_obj *obj, char **db_tab)
{
	obj->pos.x = ft_atof(db_tab[1]);
	obj->pos.y = ft_atof(db_tab[2]);
	obj->pos.z = ft_atof(db_tab[3]);
	obj->pos.w = 1;
	obj->norm_v.x = ft_atof(db_tab[4]);
	obj->norm_v.y = ft_atof(db_tab[5]);
	obj->norm_v.z = ft_atof(db_tab[6]);
	obj->norm_v.w = 0;
	obj->fov = ft_atoi(db_tab[7]);
	return ;
}

/*Fill the struct if the object is a Light.*/

void	fill_l(t_obj *obj, char **db_tab)
{
	obj->pos.x = ft_atof(db_tab[1]);
	obj->pos.y = ft_atof(db_tab[2]);
	obj->pos.z = ft_atof(db_tab[3]);
	obj->pos.w = 1;
	obj->lt_ratio = ft_atof(db_tab[4]);
	obj->color.rgb = fill_color(db_tab[5], db_tab[6], db_tab[7]);
	obj->color.r = ft_atof(db_tab[5]);
	obj->color.g = ft_atof(db_tab[6]);
	obj->color.b = ft_atof(db_tab[7]);
	return ;
}
