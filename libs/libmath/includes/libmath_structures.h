/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath_structures.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:19:11 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/23 01:25:42 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_STRUCTURES_H
# define LIBMATH_STRUCTURES_H

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct s_mat4
{
	t_tuple	x;
	t_tuple	y;
	t_tuple	z;
	t_tuple	t;
}	t_mat4;

typedef t_mat4	t_mat3;

typedef t_tuple	t_vec3;

typedef t_tuple	t_point3;

#endif
