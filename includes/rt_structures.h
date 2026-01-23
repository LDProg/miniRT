/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:19:11 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/23 01:24:48 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCTURES_H
# define RT_STRUCTURES_H

# define WIDTH 480
# define HEIGHT 210
# define AA_SAMPLES 1

# include "dynvect.h"
# include "libmath.h"
# include <stdbool.h>
# include <stdint.h>

typedef enum e_error
{
	ERR_NONE = 0,
	ERR_MALLOC = -1,
	ERR_OPEN = -2,
	ERR_IDENTIFIER = -3,
	ERR_MISSING_OBJ = -4,
	ERR_CAMERA = -5,
	ERR_LIGHT = -6,
	ERR_FORMAT = -7,
	ERR_COLOR = -8,
	ERR_RANGE = -9,
	ERR_NORMAL = -10,
	ERR_DIAMETER = -11,
	ERR_TUPLE = -12,
	ERR_MLX = -13
}	t_error;

typedef enum e_keys
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
	int			r;
	int			g;
	int			b;
}	t_color;

typedef struct s_light
{
	t_point3	position;
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
	double		radius;
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

typedef union u_shape
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_shape;

typedef struct s_object
{
	t_obj_type	type;
	t_shape		shape;
}	t_object;

typedef struct s_hit
{
	double		t;
	t_point3	point;
	t_vec3		normal;
	t_color		shape_color;
}	t_hit;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
}	t_ray;

typedef struct s_camera
{
	int32_t		fov;
	t_point3	origin;
	t_vec3		right;
	t_vec3		up;
	t_vec3		forward;
}	t_camera;

typedef struct s_mlx_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		size_line;
}	t_mlx_img;

typedef struct s_scene
{
	t_light		light;
	t_color		ambient;
	t_camera	camera;
	bool		has_ambient;
	bool		has_camera;
	bool		has_diffuse_light;
	t_dynvec	*objs;
	void		*mlx_ptr;
	void		*window_ptr;
	t_mlx_img	mlx_img;
	bool		needs_redraw;
}	t_scene;

#endif
