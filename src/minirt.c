/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/02 15:01:18 by gaducurt         ###   ########.fr       */
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
	printf(BLUE"x2 = %g\ny2 = %g\nz2 = %g\nw2 = %d\n\n"RESET, v1.x, v1.y, v1.z, v1.w);
	v1 = translate_matrix(v1, 1, 1, 1);
	printf(GREEN"x3 = %g\ny3 = %g\nz3 = %g\nw3 = %d\n\n"RESET, v1.x, v1.y, v1.z, v1.w);
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
