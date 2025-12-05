/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:20:18 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/05 14:29:44 by gaducurt         ###   ########.fr       */
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
	int		id;
	int		fov;
	int		color;
	float	lt_ratio;
	float	sp_diam;
	float	cy_diam;
	float	cy_height;
}	t_obj;


#endif

