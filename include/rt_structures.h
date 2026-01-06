/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:19:11 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 13:58:10 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCTURES_H
# define RT_STRUCTURES_H

# define WIDTH 1920
# define HEIGHT 1080
// # define FOV 60
# define BACKGROUND_COLOR 0x0000FF

# include "libmath.h"
# include "structures.h"
# include <stdbool.h>
# include <stdint.h>

typedef enum s_keys
{
	COLOR_SHIFT_KEY = 99,
	CLOSE_KEY = 65307,
	ARROW_LEFT = 65361,
	ARROW_UP,
	ARROW_RIGHT,
	ARROW_DOWN,
	MOUSE_UP = 4,
	MOUSE_DOWN,
}	t_keys;

typedef enum e_obj_type
{
	T_SPHERE,
	T_PLANE,
	T_CYLINDER
}	t_obj_type;

typedef struct s_color
{
	double		ratio;
	uint32_t	rgb;
}	t_color;

typedef struct s_mlx_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		size_line;
}	t_mlx_img;

typedef struct s_light
{
	t_point3	center;
	t_color		color;
}	t_light;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	t_color		color;
}	t_sphere;

typedef struct s_plane
{
	t_point3	center;
	t_vec3		normal;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_point3	center;
	t_point3	c_top;
	t_point3	c_bottom;
	t_vec3		axis;
	double		radius;
	double		height;
	t_color		color;
}	t_cylinder;

typedef struct s_obj_lu
{
	t_obj_type	type;
	void		*shape;
}	t_obj_lu;

typedef struct s_hit
{
	double		t;
	t_point3	point;
	t_vec3		normal;
	t_color		color;
}	t_hit;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
	t_point3	pos_inter;
	double		t;
	int			nb_inter;
	t_rgb		pix_color;
}	t_ray;

typedef struct s_camera
{
	t_point3	origin;
	t_vec3		right;
	t_vec3		up;
	t_vec3		forward;
}	t_camera;

typedef struct s_scene
{
	void		*mlx_ptr;
	void		*window_ptr;
	t_mlx_img	mlx_img;
	bool		needs_redraw;
	t_camera	camera;
	t_obj_lu		**objects;
	t_light		light;
	t_color		ambient;
}	t_scene;

typedef struct	s_pixel
{
	int	x;
	int	y;
	int	color;
}				t_pixel;


#endif
