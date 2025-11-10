/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:33:55 by ludebion          #+#    #+#             */
/*   Updated: 2025/11/10 14:04:41 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 800
# define HEIGHT 800

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <math.h>
# include "vector.h"
# include "struct.h"

/*----------PARSING----------*/

int	parsing(int ac, char **av);
// int	check_object(int fd);
int		fill_tab(int fd, t_vector *vector);
char	**multi_split(char const *s, char c1, char c2);
int		ft_strcmp(char *s1, char *s2);
t_obj	init_obj();
int		fill_id(char *s);
void	fill_a(t_obj *obj, char **db_tab);
void	fill_c(t_obj *obj, char **db_tab);
void	fill_l(t_obj *obj, char **db_tab);
void	fill_pl(t_obj *obj, char **db_tab);
void	fill_sp(t_obj *obj, char **db_tab);
void	fill_cy(t_obj *obj, char **db_tab);


/*----------TESTS----------*/

void	print_double_tab(char **double_tab);

#endif
