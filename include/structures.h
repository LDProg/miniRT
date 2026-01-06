/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:20:18 by gaducurt          #+#    #+#             */
/*   Updated: 2026/01/06 13:23:34 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "mathvect.h"

enum	e_type
{
	A,
	C,
	L,
	PL,
	SP,
	CY,
};

typedef struct	s_rgb
{
	int		rgb;
	double	r;
	double	g;
	double	b;
}				t_rgb;

typedef struct s_obj
{
	t_point3	pos;
	t_vec3		norm_v;
	int			type;
	int			fov;
	// int			color;
	t_rgb		color;
	double		lt_ratio;
	double		sp_diam;
	double		cy_diam;
	double		cy_height;
}	t_obj;


#endif

