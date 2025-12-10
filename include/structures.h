/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:20:18 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/10 10:54:06 by gaducurt         ###   ########.fr       */
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

typedef struct s_obj
{
	t_tuple	pos;
	t_tuple	ov_pos;
	int		type;
	int		fov;
	int		color;
	double	lt_ratio;
	double	sp_diam;
	double	cy_diam;
	double	cy_height;
}	t_obj;


#endif

