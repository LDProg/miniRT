/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:19:11 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/15 16:19:23 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCTURES_H
# define RT_STRUCTURES_H

# define WIDTH 800
# define HEIGHT 450
# define FOV 60

# include <stdbool.h>
# include "libmath.h"

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

typedef struct s_mlx_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		size_line;
}	t_mlx_img;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
	double		t;
	int			nb_inter;
	int			pix_color;
}	t_ray;

typedef struct s_camera
{
	t_point3	origin;
	t_vec3		direction;
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
}	t_scene;

typedef struct	s_pixel
{
	int	x;
	int	y;
	int	color;
}				t_pixel;


#endif
