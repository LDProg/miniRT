/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:37:31 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/08 12:54:29 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynvect.h"
#include <stdio.h>

void	ft_free_vector(t_dynvec *vector)
{
	if (vector->array)
		free(vector->array);
	free(vector);
}
