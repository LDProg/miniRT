/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:51:14 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/12 13:30:09 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectlib.h"

void	ft_init_vector(t_vector *vector, size_t value_size)
{
	vector->capacity = 0;
	vector->len = 0;
	vector->array = NULL;
	vector->size_type = value_size;
}
