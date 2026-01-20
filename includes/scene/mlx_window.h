/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:20:02 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/08 16:21:28 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WINDOW_H
# define MLX_WINDOW_H

# include "rt_structures.h"

void	mlx_full_init(t_scene *scene);

int		handle_mouse_hook(int button, int x, int y, t_scene *scene);
int		handle_keypress_hook(int keycode, t_scene *scene);
int		handle_close_hook(t_scene *scene);
int		loop_hook(t_scene *scene);

void	my_pixel_put(t_mlx_img *img, int x, int y, int color);
void	mlx_clear(t_scene *scene);

#endif
