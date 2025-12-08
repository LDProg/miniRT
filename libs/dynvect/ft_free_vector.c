/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:37:31 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/08 13:16:28 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynvect.h"

void	ft_free_vector(t_dynvec *vector)
{
	if (vector->array)
		free(vector->array);
	free(vector);
}
