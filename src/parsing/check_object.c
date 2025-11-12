/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:01:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/12 10:38:44 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "get_next_line_bonus.h"
#include "minirt.h"
#include "vector.h"
#include <stdio.h>

void	db_free(char **db_tab)
{
	int	i;
	
	i = 0;
	while (db_tab[i])
	{
		free(db_tab[i]);
		i++;
	}
	free(db_tab);
}

int	check_id(char *s)
{
	(void)s;
	return (0);
}

void	ft_replace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = ' ';
		i++;
	}
}

char	**new_tab(int fd)
{
	char	*line;
	char	**db_tab;

	line = get_next_line(fd);
	db_tab = multi_split(line, '\t', ',');
	free(line);
	if (!db_tab)
		return (NULL);
	return (db_tab);
}

static void	fill_obj(t_obj *obj, char **db_tab)
{
	if (obj->id == A)
		fill_a(obj, db_tab);
	if (obj->id == C)
		fill_c(obj, db_tab);
	if (obj->id == L)
		fill_l(obj, db_tab);
	if (obj->id == PL)
		fill_pl(obj, db_tab);
	if (obj->id == SP)
		fill_sp(obj, db_tab);
	if (obj->id == CY)
		fill_cy(obj, db_tab);
}

int	fill_tab(int fd, t_vector *vector)
{
	char	**db_tab;
	t_obj	obj;

	ft_init_vector(vector, sizeof(t_obj));
	db_tab = new_tab(fd);
	if (!db_tab)
	{
		close(fd);
		free(db_tab);
		ft_free_vector(vector);
		return (1);
	}
	while (db_tab)
	{
		obj = init_obj();
		fill_id(&obj, db_tab[0]);
		fill_obj(&obj, db_tab);
		db_free(db_tab);
		db_tab = new_tab(fd);
		if (!db_tab)
		{
			free(db_tab);
			break;
		}
		ft_vector_addone(vector, &obj);
	}
	ft_vector_addone(vector, &obj);
	// print_vector(vector);
	ft_free_vector(vector);
	return (0);
}
