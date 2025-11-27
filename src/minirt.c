/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:34:18 by ludebion          #+#    #+#             */
/*   Updated: 2025/11/27 07:15:40 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing/parsing.h"
#include "vectlib.h"
#include <fcntl.h>
#include <stdio.h>

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
	printf("Hello RT!\n");
	return (EXIT_SUCCESS);
}
