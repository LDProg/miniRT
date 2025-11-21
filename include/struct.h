/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:20:18 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/19 17:01:27 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum	e_type
{
	A,
	C,
	L,
	PL,
	SP,
	CY,
};

typedef struct	s_pos
{
	float	x;
	float	y;
	float	z;
	int		w;
}				t_pos;

typedef struct	s_obj
{
	t_pos	pos;
	t_pos	ov_pos;
	int		id;
	int		fov;
	int		color;
	// int		r;
	// int		g;
	// int		b;
	float	lt_ratio;
	// float	x;
	// float	y;
	// float	z;
	// float	ov_x;
	// float	ov_y;
	// float	ov_z;
	float	sp_diam;
	float	cy_diam;
	float	cy_height;
}			t_obj;


#endif

