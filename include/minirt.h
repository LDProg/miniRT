/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:33:55 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/11 13:00:44 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// # define WIDTH 800
// # define HEIGHT 800

# define RESET "\033[1;0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"

#include "structures.h"
#include "rt_structures.h"
#include "dynvect.h"

/*----------RAY----------*/

/*----------INTERSECT----------*/
t_inter	intersect_sphere(t_obj *sphere, t_ray ray);

/*----------TEST----------*/
// void	print_double_tab(char **double_tab);
// void	print_struct(t_obj *obj);
// void	print_vector(t_dynvec *vector);
t_tuple	fill_vect_test(double x, double y, double z, double w);
void	test_vect();
t_ray	init_ray();
void	print_tuple(t_tuple tuple);

#endif
