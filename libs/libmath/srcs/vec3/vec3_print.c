/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 01:18:22 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/31 06:07:19 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath_structures.h"
#include <stdio.h>

void	vec3_print(t_vec3 v, const char *name)
{
	printf("\n=== Vec3: %s ===\n", name);
	printf("┌                   ┐\n");
	printf("│ x: %8.3f │\n", v.x);
	printf("│ y: %8.3f │\n", v.y);
	printf("│ z: %8.3f │\n", v.z);
	printf("└                   ┘\n");
}
