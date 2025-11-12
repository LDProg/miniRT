/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:15:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/12 11:55:50 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Check if the filename ending by .rt*/

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

/*Check if the args are valides*/

int	check_args(int ac, char **av)
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
