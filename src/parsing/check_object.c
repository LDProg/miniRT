/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:01:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/12 17:35:30 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "mylib.h"
#include "get_next_line_bonus.h"
#include "minirt.h"
#include "vectlib.h"
#include <stdio.h>

/*Read the line with gnl and convert it in char**.*/

static char	**new_tab(int fd)
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

/*Fill the struct depending of the first data.*/

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

/*Each line is stocked in a struct t_obj. Then, the struct is stocked in
the vector array.*/

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
		ft_vector_addone(vector, &obj); //Need to protect if the adding fail.
	}
	ft_vector_addone(vector, &obj); //Need to protect if the adding fail.
	// print_vector(vector);
	ft_free_vector(vector);
	return (0);
}
