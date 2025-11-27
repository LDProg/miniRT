/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:38:29 by ludebion          #+#    #+#             */
/*   Updated: 2025/11/27 10:50:21 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "structures.h"
# include <stdbool.h>

t_tuple	create_tuple(double x, double y, double z, double w);
t_tuple	create_point(double x, double y, double z);
t_tuple	create_vector(double x, double y, double z);
bool	is_point(t_tuple t);
bool	is_vector(t_tuple t);


#endif
