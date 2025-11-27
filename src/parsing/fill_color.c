/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:27:41 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/27 07:14:18 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fill_color(char *r, char *g, char *b)
{
	int	rgb_value;

	rgb_value = ft_atoi(r);
	// printf(RED"rbg = %d\n"RESET, rgb_value);
	rgb_value = (rgb_value << 8) + ft_atoi(g);
	// printf(BLUE"rbg = %d\n"RESET, rgb_value);
	rgb_value = (rgb_value << 8) + ft_atoi(b);
	// printf(GREEN"rbg = %d\n"RESET, rgb_value);
	// printf("\n");
	return (rgb_value);
}
