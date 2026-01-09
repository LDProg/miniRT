/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:11:56 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/08 17:26:01 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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
