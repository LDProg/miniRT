/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:03:58 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/10 16:45:42 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	print_double_tab(char **double_tab)
{
	int	i;

	i = 0;
    while (double_tab[i])
	{
		ft_putendl_fd(double_tab[i], 1);
		i++;
	}
	
}
