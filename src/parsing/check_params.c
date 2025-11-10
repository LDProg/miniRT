/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:14:46 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/10 14:04:21 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] - s2[i] == 0)
		return (1);
	return (0);
}

t_obj	init_obj()
{
	t_obj	obj;
	
	obj.id = 0;
	obj.fov = 0;
	obj.r = 0;
	obj.g = 0;
	obj.b = 0;
	obj.lt_ratio = 0;
	obj.x = 0;
	obj.y = 0;
	obj.z = 0;
	obj.ov_x = 0;
	obj.ov_y = 0;
	obj.ov_z = 0;
	obj.sp_diam = 0;
	obj.cy_diam = 0;
	obj.cy_height = 0;
	return (obj);
}

int	fill_id(char *s)
{
	if (ft_strcmp(s, "A"))
		return (A);
	if (ft_strcmp(s, "C"))
		return (C);
	if (ft_strcmp(s, "L"))
		return (L);
	if (ft_strcmp(s, "pl"))
		return (PL);
	if (ft_strcmp(s, "sp"))
		return (SP);
	if (ft_strcmp(s, "cy"))
		return (CY);
	return (-1);
}
