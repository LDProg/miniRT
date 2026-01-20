/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 01:18:22 by ludebion          #+#    #+#             */
/*   Updated: 2025/12/31 06:06:51 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath_structures.h"
#include <stdio.h>

void	mat4_print(t_mat4 m, const char *name)
{
	printf("\n=== Matrix: %s ===\n", name);
	printf("┌                                           ┐\n");
	printf("│ %8.3f %8.3f %8.3f %8.3f │\n", m.x.x, m.y.x, m.z.x, m.t.x);
	printf("│ %8.3f %8.3f %8.3f %8.3f │\n", m.x.y, m.y.y, m.z.y, m.t.y);
	printf("│ %8.3f %8.3f %8.3f %8.3f │\n", m.x.z, m.y.z, m.z.z, m.t.z);
	printf("│ %8.3f %8.3f %8.3f %8.3f │\n", m.x.w, m.y.w, m.z.w, m.t.w);
	printf("└                                           ┘\n");
}

void	mat4_print_basis(t_mat4 m, const char *name)
{
	printf("\n=== Basis: %s ===\n", name);
	printf("Right   (X): (%8.3f, %8.3f, %8.3f)\n", m.x.x, m.x.y, m.x.z);
	printf("Up      (Y): (%8.3f, %8.3f, %8.3f)\n", m.y.x, m.y.y, m.y.z);
	printf("Forward (Z): (%8.3f, %8.3f, %8.3f)\n", m.z.x, m.z.y, m.z.z);
	printf("Position(T): (%8.3f, %8.3f, %8.3f)\n", m.t.x, m.t.y, m.t.z);
	printf("\n");
}
