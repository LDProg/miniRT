/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:03:58 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/12 10:38:16 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "struct.h"
#include <stdio.h>
#include "vector.h"
#include "minirt.h"

void	print_double_tab(char **double_tab)
{
	int	i;

	i = 0;
    while (double_tab[i])
	{
		ft_putendl_fd(double_tab[i], 1);
		i++;
	}
}

void	print_struct(t_obj *obj)
{
	printf("id = %d\n", obj->id);
	printf("fov = %d\n", obj->fov);
	printf("r = %d\n", obj->r);
	printf("g = %d\n", obj->g);
	printf("b = %d\n", obj->b);
	printf("lt_ratio = %g\n", obj->lt_ratio);
	printf("x = %g\n", obj->x);
	printf("y = %g\n", obj->y);
	printf("z = %g\n", obj->z);
	printf("ov_x = %g\n", obj->ov_x);
	printf("ov_y = %g\n", obj->ov_y);
	printf("ov_z = %g\n", obj->z);
	printf("sp_diam = %g\n", obj->sp_diam);
	printf("cy_diam = %g\n", obj->cy_diam);
	printf("cy_height = %g\n", obj->cy_height);
	printf("\n");
}

void	print_vector(t_vector *vector)
{
	t_obj	*p;
	size_t	i;

	i = 0;
	while (i < vector->len)
	{
		p = (t_obj *)((unsigned char *)vector->array + i * vector->size_type);
		print_struct(p);
		i++;
	}
}
