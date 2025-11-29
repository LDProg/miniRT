/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/11/29 13:51:13 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing/parsing.h"
#include "dynvect.h"
#include <fcntl.h>
#include <stdio.h>
#include "mathvect.h"
#include "minirt.h"

t_tuple	fill_vect_test()
{
	t_tuple res;

	res.x = 1.0;
	res.y = -3.0;
	res.z = 8.0;
	res.w = 0;
	return (res);
}

int	main(int ac, char **av)
{
	t_vector	*vector;
	t_tuple		v;
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
	v = fill_vect_test();
	printf(BLUE"x = %g\ny = %g\nz = %g\nw = %d\n\n"RESET, v.x, v.y, v.z, v.w);
	v = scalar_div(v, -2);
	printf(GREEN"x = %g\ny = %g\nz = %g\nw = %d\n\n"RESET, v.x, v.y, v.z, v.w);
	printf("Hello RT!\n");
	return (EXIT_SUCCESS);
}
