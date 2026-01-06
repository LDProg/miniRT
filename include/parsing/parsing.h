/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:52:51 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/06 14:49:00 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "dynvect.h"
# include "structures.h"
# include "rt_structures.h"

int		check_args(int ac, char **av);
int		fill_tab(int fd, t_dynvec *vector);
char	**multi_split(char const *s, char c1, char c2);
int		ft_strcmp(char *s1, char *s2);
t_obj	init_obj(void);
void	fill_type(t_obj *obj, char *s);
void	fill_a(t_obj *obj, char **db_tab);
void	fill_c(t_obj *obj, char **db_tab);
void	fill_l(t_obj *obj, char **db_tab);
void	fill_pl(t_obj *obj, char **db_tab);
void	fill_sp(t_obj *obj, char **db_tab);
void	fill_cy(t_obj *obj, char **db_tab);
int		fill_color(char *r, char *g, char *b);

t_obj_lu	*create_plane(t_point3 center, t_vec3 normal, uint32_t rgb);
t_obj_lu	*create_sphere(t_point3 center, double radius, uint32_t rgb);
t_obj_lu	*create_cylinder(t_point3 center, t_point3 vz, double radius,
			double height, uint32_t rgb);

#endif
