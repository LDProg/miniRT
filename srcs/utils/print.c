/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:05:32 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/08 15:59:21 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynvect.h"
#include "rt_structures.h"
#include <stdio.h>

static void	print_color(uint32_t rgb)
{
	int	r;
	int	g;
	int	b;

	r = (rgb >> 16) & 0xFF;
	g = (rgb >> 8) & 0xFF;
	b = rgb & 0xFF;
	printf("RGB(%d, %d, %d)", r, g, b);
}

static void	print_point3(t_point3 p)
{
	printf("(%.2f, %.2f, %.2f)", p.x, p.y, p.z);
}

static void	print_vec3(t_vec3 v)
{
	printf("(%.2f, %.2f, %.2f)", v.x, v.y, v.z);
}

static void	print_sphere(t_sphere *sphere)
{
	printf("SPHERE:\n");
	printf("  Center: ");
	print_point3(sphere->center);
	printf("\n");
	printf("  Radius: %.2f\n", sphere->radius);
	printf("  Color: ");
	print_color(sphere->color.rgb);
	printf("\n");
}

static void	print_plane(t_plane *plane)
{
	printf("PLANE:\n");
	printf("  Point: ");
	print_point3(plane->center);
	printf("\n");
	printf("  Normal: ");
	print_vec3(plane->normal);
	printf("\n");
	printf("  Color: ");
	print_color(plane->color.rgb);
	printf("\n");
}

static void	print_cylinder(t_cylinder *cylinder)
{
	printf("CYLINDER:\n");
	printf("  Center: ");
	print_point3(cylinder->center);
	printf("\n");
	printf("  Axis: ");
	print_vec3(cylinder->axis);
	printf("\n");
	printf("  Radius: %.2f\n", cylinder->radius);
	printf("  Height: %.2f\n", cylinder->height);
	printf("  Color: ");
	print_color(cylinder->color.rgb);
	printf("\n");
}

void	print_obj(t_object *obj)
{
	if (obj->type == T_SPHERE)
		print_sphere(&obj->shape.sphere);
	else if (obj->type == T_PLANE)
		print_plane(&obj->shape.plane);
	else if (obj->type == T_CYLINDER)
		print_cylinder(&obj->shape.cylinder);
	else
		printf("UNKNOWN OBJECT TYPE\n");
}

void	print_all_objs(t_dynvec *objs)
{
	size_t		i;
	t_object	*obj_array;

	obj_array = (t_object *)objs->array;
	printf("\n=== OBJECTS (%zu) ===\n\n", objs->len);
	i = 0;
	while (i < objs->len)
	{
		printf("[%zu] ", i);
		print_obj(&obj_array[i]);
		printf("\n");
		i++;
	}
}

void	print_scene(t_scene *scene, t_dynvec *objs)
{
	printf("\n========== SCENE ==========\n\n");
	printf("AMBIENT LIGHT:\n");
	printf("  Ratio: %.2f\n", scene->ambient.ratio);
	printf("  Color: ");
	print_color(scene->ambient.rgb);
	printf("\n\n");
	printf("CAMERA:\n");
	printf("  Position: ");
	print_point3(scene->camera.origin);
	printf("\n");
	printf("  Orientation: ");
	print_vec3(scene->camera.forward);
	printf("\n");
	printf("  FOV: %d°\n", scene->camera.fov);
	printf("\n");
	printf("LIGHT:\n");
	printf("  Position: ");
	print_point3(scene->light.position);
	printf("\n");
	printf("  Brightness: %.2f\n", scene->light.color.ratio);
	printf("\n");
	print_all_objs(objs);
	printf("===========================\n\n");
}
