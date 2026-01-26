/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:37:31 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/26 10:45:29 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynvect.h"
#include <stdio.h>

void	ft_free_vector(t_dynvec *vector)
{
	if (!vector)
		return ;
	if (vector->array)
		free(vector->array);
	free(vector);
}
