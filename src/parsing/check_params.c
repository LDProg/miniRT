/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:14:46 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/10 12:46:37 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] - s2[i] == 0)
		return (1);
	return (0);
}

int	fill_id(char *s)
{
	if (ft_strcmp(s, "A"))
		return (A);
	if (ft_strcmp(s, "C"))
		return (C);
	if (ft_strcmp(s, "L"))
		return (L);
	if (ft_strcmp(s, "pl"))
		return (PL);
	if (ft_strcmp(s, "sp"))
		return (SP);
	if (ft_strcmp(s, "cy"))
		return (CY);
	return (-1);
}
