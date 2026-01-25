/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 01:18:22 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/23 17:17:33 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include <stdio.h>

void	vec3_print(t_vec3 v, const char *name)
{
	printf("\n Vec3: %s \n", name);
	printf("┌                   ┐\n");
	printf("│    x: %8.3f    │\n", v.x);
	printf("│    y: %8.3f    │\n", v.y);
	printf("│    z: %8.3f    │\n", v.z);
	printf("└                   ┘\n");
}

void	print_normalized_vector(t_vec3 v)
{
	t_vec3	vn;

	vn = vec3_normalize(v);
	printf("Your normalized vector :\n\t%1.3f,%1.3f,%1.3f\n", vn.x, vn.y, vn.z);
}
