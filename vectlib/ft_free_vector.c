/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:37:31 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/12 13:29:59 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectlib.h"

void	ft_free_vector(t_vector *vector)
{
	if (vector->array)
		free(vector->array);
	free(vector);
}
