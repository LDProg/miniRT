/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaducurt.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:13:23 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/08 18:56:06 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GADUCURT_H
# define GADUCURT_H

# define RESET "\033[1;0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"

# include "rt_structures.h"
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

typedef struct s_rgb
{
	int		rgb;
	double	r;
	double	g;
	double	b;
}	t_rgb;

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

/*----------RAY----------*/

/*----------INTERSECT----------*/
void	intersect_sphere(t_obj *sphere, t_ray *ray, t_obj *d_light,
			t_obj *a_light);
void	intersect_plan(t_obj *plan, t_ray *ray);
int		find_intersect(t_ray *ray, t_dynvec *tab_vec, t_obj *d_light,
			t_obj *a_light);
// t_color	diffuse_lt(t_ray *ray, t_obj *obj, t_obj *light);
t_obj	*get_d_light(t_dynvec *tab_vec);
t_obj	*get_a_light(t_dynvec *tab_vec);
t_obj	*get_cam(t_dynvec *tab_vec);
t_rgb	compute_color(double coef, t_rgb l_color, t_rgb o_color);
// t_color	compute_rgb(t_color c);
t_rgb	add_colors(t_rgb diff, t_rgb amb);
void	handle_ray(double t, t_ray *ray, t_obj *obj, t_obj *d_light,
			t_obj *a_light);

/*----------TEST----------*/
t_tuple	fill_vect_test(double x, double y, double z, double w);
void	test_vect(void);
t_ray	init_ray(void);
void	print_tuple(t_tuple tuple);

#endif
