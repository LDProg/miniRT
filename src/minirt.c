/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/03 15:23:23 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing/parsing.h"
#include "dynvect.h"
#include <fcntl.h>
#include <stdio.h>
#include "mathvect.h"
#include "minirt.h"

t_tuple	fill_vect_test(float x, float y, float z, float w)
{
	t_tuple res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = w;
	return (res);
}

void	test_vect()
{
	t_tuple	v1;
	
	v1 = fill_vect_test(1, 2, 3, 0);
	printf(BLUE"x1 = %g\ny1 = %g\nz1 = %g\nw1 = %d\n\n"RESET, v1.x, v1.y, v1.z, v1.w);
	v1 = all_rotate_matrix(v1, 30, 15, 60);
	printf(GREEN"x1 = %g\ny1 = %g\nz1 = %g\nw1 = %d\n\n"RESET, v1.x, v1.y, v1.z, v1.w);
	// v = scalar_div(v, -2);
	// printf(GREEN"dot product = %g\n"RESET, dot_product(v1, v2));
	// printf(GREEN"x = %g\ny = %g\nz = %g\nw = %d\n\n"RESET, v.x, v.y, v.z, v.w);
}

int	main(int ac, char **av)
{
	t_vector	*vector;
	int			fd;

	if (check_args(ac, av))
		return (1);
	fd = open(av[1], O_RDONLY);
	vector = malloc((sizeof(t_vector)));
	if (!vector)
	{
		close(fd);
		return (1);
	}
	if (fill_tab(fd, vector))
	{
		ft_putstr_fd("The file is not valid", 2);
		return (1);
	}
	test_vect();
	printf("Hello RT!\n");
	return (EXIT_SUCCESS);
}
