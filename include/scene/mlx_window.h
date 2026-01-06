/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:20:02 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/30 11:16:03 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WINDOW_H
# define MLX_WINDOW_H

# include "rt_structures.h"

/*Init*/
void	mlx_full_init(t_scene *scene);

/*Hooks*/
int		handle_mouse_hook(int button, int x, int y, t_scene *scene);
int		handle_keypress_hook(int keycode, t_scene *scene);
int		handle_close_hook(t_scene *scene);
int		loop_hook(t_scene *scene);

/*Utils*/
void	my_pixel_put(t_mlx_img *img, int x, int y, int color);
int		get_color(double red, double green, double blue);
void	mlx_clear(t_scene *scene);

#endif
