/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/11/07 14:12:55 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vector.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_vector	*vector;
	int			fd;
	
	(void)vector;
	if (parsing(ac, av))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (check_object(fd))
	{
		ft_putstr_fd("The file is not valid", 2);
		return (1);
	}
	printf("Hello RT!\n");
	return (EXIT_SUCCESS);
}
