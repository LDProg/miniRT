/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 05:20:02 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/05 04:27:31 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "rt_structures.h"

/*Init*/
void	scene_init(t_scene *scene);
void	mlx_full_init(t_scene *scene);

/*Hooks*/
int		handle_mouse_hook(int button, int x, int y, t_scene *scene);
int		handle_keypress_hook(int keycode, t_scene *scene);
int		handle_close_hook(t_scene *scene);
int		loop_hook(t_scene *scene);

/*Utils*/
void	my_pixel_put(t_mlx_img *img, int x, int y, int color);
void	mlx_clear(t_scene *scene);

#endif
