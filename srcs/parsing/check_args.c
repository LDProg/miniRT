/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:11:56 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/23 15:37:49 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mylib.h"
#include <stdbool.h>

bool	check_suffix(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (len <= 3)
		return (false);
	if (ft_strcmp(s + len - 3, ".rt"))
		return (false);
	return (true);
}

bool	check_args(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Insert a '.rt' file as argument.\n", STDERR_FILENO);
		return (false);
	}
	if (!check_suffix(av[1]))
	{
		ft_putstr_fd("The file need to be a '.rt' format.", STDERR_FILENO);
		return (false);
	}
	return (true);
}

bool	check_format(char **trim_line)
{
	int	i;

	i = 1;
	while (trim_line[i])
	{
		if (!ft_isdigit(trim_line[i][0]) && trim_line[i][0] != '-')
			return (false);
		i++;
	}
	return (true);
}
