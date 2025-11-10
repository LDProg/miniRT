/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:01:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/10 12:37:22 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "get_next_line_bonus.h"
#include "struct.h"
#include "vector.h"

int	check_id(char *s)
{
	(void)s;
	return (0);
}

// int	count_line(char *file)
// {
// 	int	fd;

// 	fd = open(file, O_RDONLY);
	
// }

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

int	fill_tab(int fd, t_vector *vector)
{
	(void)fd;
	(void)vector;
	char	**double_tab;
	t_obj	obj;

	ft_init_vector(vector, sizeof(t_obj));
	double_tab = new_tab(fd);
	if (!double_tab)
	{
		close(fd);
		free(double_tab);
		ft_free_vector(vector);
		return (1);
	}
	while (double_tab)
	{
		obj.id = fill_id(double_tab[0]);
	}
	print_double_tab(double_tab);
	return (0);
}
