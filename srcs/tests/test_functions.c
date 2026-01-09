/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:03:58 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/08 16:16:31 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynvect.h"
#include "gaducurt.h"
#include "libft.h"
#include "minirt.h"
#include "rt_structures.h"
#include <stdio.h>

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
	printf("type = %d\n", obj->type);
	printf("fov = %d\n", obj->fov);
	printf("r = %d\n", obj->color.rgb);
	printf("lt_ratio = %g\n", obj->lt_ratio);
	printf("x = %g\n", obj->pos.x);
	printf("y = %g\n", obj->pos.y);
	printf("z = %g\n", obj->pos.z);
	printf("ov_x = %g\n", obj->norm_v.x);
	printf("ov_y = %g\n", obj->norm_v.y);
	printf("ov_z = %g\n", obj->norm_v.z);
	printf("sp_diam = %g\n", obj->sp_diam);
	printf("cy_diam = %g\n", obj->cy_diam);
	printf("cy_height = %g\n", obj->cy_height);
	printf("\n");
}

/*Display the content of vector->array.*/

void	print_vector(t_dynvec *vector)
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

t_tuple	fill_vect_test(double x, double y, double z, double w)
{
	t_tuple	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = w;
	return (res);
}

void	test_vect(void)
{
	t_tuple	v1;

	v1 = fill_vect_test(1, 2, 3, 0);
	printf(BLUE "x1 = %g\ny1 = %g\nz1 = %g\nw1 = %g\n\n" RESET, v1.x, v1.y,
		v1.z, v1.w);
	v1 = all_rotate_matrix(v1, 30, 15, 60);
	printf(GREEN "x1 = %g\ny1 = %g\nz1 = %g\nw1 = %g\n\n" RESET, v1.x, v1.y,
		v1.z, v1.w);
}

t_ray	init_ray(void)
{
	t_ray	ray;

	ray.origin.x = 0;
	ray.origin.y = 0;
	ray.origin.z = 0;
	ray.origin.w = 1;
	ray.direction.x = 0;
	ray.direction.y = 0;
	ray.direction.z = 20;
	ray.direction.w = 0;
	return (ray);
}

// void	print_tuple(t_tuple tuple)
// {
// 	printf(GREEN "tuple.x = %g\ntuple.y = %g\ntuple.z = %g\ntuple.w =
// 		%g\n" RESET, tuple.x, tuple.y, tuple.z, tuple.w);
// }
