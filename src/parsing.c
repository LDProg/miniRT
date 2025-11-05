/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:15:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/05 15:44:33 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line_bonus.h"

int	check_object(int fd)
{
	// (void)fd;
	char	*line;

	line = get_next_line(fd);
	return (0);
}

int	check_suff(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len <= 3)
		return (1);
	if (s[len - 3] == '.' && s[len - 2] == 'r' && s[len - 1] == 't')
		return (0);
	return (1);
}

int	parsing(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("The program need one file in input !\n", 2);
		return (1);
	}
	if (check_suff(av[1]))
	{
		ft_putstr_fd("The file need to be a .rt format", 2);
		return (1);
	}
	return (0);
}
