/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:33:55 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 08:44:27 by gaducurt         ###   ########.fr       */
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
void	intersect_sphere(t_obj *sphere, t_ray *ray, t_obj *d_light, t_obj *a_light);
void	intersect_plan(t_obj *plan, t_ray *ray);
int		find_intersect(t_ray *ray, t_dynvec *tab_vec, t_obj *d_light, t_obj *a_light);
// t_color	diffuse_lt(t_ray *ray, t_obj *obj, t_obj *light);
t_obj	*get_d_light(t_dynvec *tab_vec);
t_obj	*get_a_light(t_dynvec *tab_vec);
t_obj	*get_cam(t_dynvec *tab_vec);
t_color	compute_color(double coef, t_color l_color, t_color o_color);
// t_color	compute_rgb(t_color c);
t_color	add_colors(t_color diff, t_color amb);
void	handle_ray(double t, t_ray *ray, t_obj *obj, t_obj *d_light, t_obj *a_light);

/*----------TEST----------*/
t_tuple	fill_vect_test(double x, double y, double z, double w);
void	test_vect();
t_ray	init_ray();
void	print_tuple(t_tuple tuple);

#endif
