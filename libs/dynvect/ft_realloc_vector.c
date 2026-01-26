/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:37:34 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/26 10:46:38 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynvect.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ndest;
	const char		*nsrc;

	i = 0;
	ndest = dest;
	nsrc = src;
	if (dest == 0 && src == 0)
		return (NULL);
	while (i < n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (dest);
}

int	ft_realloc_vector(t_dynvec *vector)
{
	void	*new_tab;

	if (vector->capacity == 0)
		vector->capacity = VECT_SIZE;
	else
		vector->capacity *= 2;
	new_tab = malloc(vector->capacity * vector->size_type);
	if (!new_tab)
		return (0);
	ft_memcpy(new_tab, vector->array, vector->size_type * vector->len);
	if (vector->array)
		free(vector->array);
	vector->array = new_tab;
	return (1);
}
