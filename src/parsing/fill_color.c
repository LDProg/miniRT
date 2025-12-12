/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:27:41 by gaducurt          #+#    #+#             */
/*   Updated: 2025/12/12 14:33:48 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fill_color(char *r, char *g, char *b)
{
	int	rgb_value;

	rgb_value = ft_atoi(r);
	rgb_value = (rgb_value << 8) + ft_atoi(g);
	rgb_value = (rgb_value << 8) + ft_atoi(b);
	return (rgb_value);
}
