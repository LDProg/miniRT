/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynvect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:30:01 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/08 13:16:20 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNVECT_H
# define DYNVECT_H

# include <stdlib.h>

# define VECT_SIZE 4

typedef struct s_dynvec
{
	void	**array;
	size_t	len;
	size_t	size_type;
	size_t	capacity;
}			t_dynvec;

void	ft_init_vector(t_dynvec *vector, size_t value_size);
int		ft_realloc_vector(t_dynvec *vector);
int		ft_vector_addone(t_dynvec *vector, void *element);
void	ft_free_vector(t_dynvec *vector);

#endif
