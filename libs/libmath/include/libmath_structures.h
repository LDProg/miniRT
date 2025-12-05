/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath_structures.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:19:11 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/05 07:38:13 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_STRUCTURES_H
# define LIBMATH_STRUCTURES_H

# define EPSILON 0.0001

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct s_mat4
{
	double	m[4][4];
}	t_mat4;

typedef t_tuple	t_vec3;

typedef t_tuple	t_point3;

#endif
