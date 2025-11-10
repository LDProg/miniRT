/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:01:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/10 14:28:12 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "get_next_line_bonus.h"
#include "minirt.h"
#include "vector.h"

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
	char	**double_tab;

	line = get_next_line(fd);
	if (line)
		ft_replace(line);
	double_tab = multi_split(line, ' ', ',');
	free(line);
	if (!double_tab)
		return (NULL);
	return (double_tab);
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
	obj = init_obj();
	if (!db_tab)
	{
		close(fd);
		free(db_tab);
		ft_free_vector(vector);
		return (1);
	}
	print_double_tab(db_tab);
	while (db_tab)
	{
		fill_id(&obj, db_tab[0]);
		fill_obj(&obj, db_tab);
	}
	return (0);
}
