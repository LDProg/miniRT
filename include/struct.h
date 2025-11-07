/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:20:18 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/07 10:33:04 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum	e_type
{
	A,
	C,
	L,
	SP,
	PL,
	CY,
};

typedef struct	s_obj
{
	int		id;
	int		fov;
	int		r;
	int		g;
	int		b;
	float	lt_ratio;
	float	x;
	float	y;
	float	z;
	float	ov_x;
	float	ov_y;
	float	ov_z;
	float	sp_diam;
	float	cy_diam;
	float	cy_height;
}			t_obj;

#endif

