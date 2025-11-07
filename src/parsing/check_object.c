/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:01:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/07 18:23:06 by gaducurt         ###   ########.fr       */
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

// int	check_object(int fd)
int	fill_tab(int fd, t_vector *vector)
{
	(void)fd;
	(void)vector;
	// t_obj	obj;
	
	return (0);
}
