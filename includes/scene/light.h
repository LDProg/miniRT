/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 04:43:37 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/20 17:36:28 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "rt_structures.h"

uint32_t	compute_hit_color(t_hit hit, t_color a_light, t_light d_light,
				t_scene scene);

#endif
