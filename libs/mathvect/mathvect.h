/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathvect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:51:41 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/28 16:55:55 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHVECT_H
# define MATHVECT_H

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	int		w;
}	t_tuple;

t_tuple	add_vect_point(t_tuple vector, t_tuple point);

#endif
