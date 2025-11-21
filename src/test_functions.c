/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:03:58 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/21 13:51:10 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "struct.h"
#include <stdio.h>
#include "vectlib.h"
#include "minirt.h"

/*Display a char**.*/

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

/*Display a struct t_obj.*/

void	print_struct(t_obj *obj)
{
	printf("id = %d\n", obj->id);
	printf("fov = %d\n", obj->fov);
	printf("r = %d\n", obj->color);
	// printf("r = %d\n", obj->r);
	// printf("g = %d\n", obj->g);
	// printf("b = %d\n", obj->b);
	printf("lt_ratio = %g\n", obj->lt_ratio);
	printf("x = %g\n", obj->pos.x);
	printf("y = %g\n", obj->pos.y);
	printf("z = %g\n", obj->pos.z);
	printf("ov_x = %g\n", obj->ov_pos.x);
	printf("ov_y = %g\n", obj->ov_pos.y);
	printf("ov_z = %g\n", obj->ov_pos.z);
	printf("sp_diam = %g\n", obj->sp_diam);
	printf("cy_diam = %g\n", obj->cy_diam);
	printf("cy_height = %g\n", obj->cy_height);
	printf("\n");
}

/*Display the content of vector>array.*/

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
