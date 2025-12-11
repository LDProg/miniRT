/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 06:44:37 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/11 11:05:43 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "dynvect.h"
# include "structures.h"

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

#endif
