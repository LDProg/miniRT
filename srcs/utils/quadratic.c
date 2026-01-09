/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:38:33 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/08 16:00:03 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_structures.h"
#include <math.h>

static void	ft_swap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static bool	check_quadratic_roots(double *t0, double *t1)
{
	if (*t0 > *t1)
		ft_swap(t0, t1);
	if (*t0 < 0 && *t1 < 0)
		return (false);
	if (*t0 < 0)
		*t0 = *t1;
	return (true);
}

bool	solve_quadatric(double a, double b, double c, double *t0)
{
	double	discr;
	double	t1;
	double	q;

	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (false);
	else if (discr == 0)
	{
		*t0 = -0.5 * b / a;
		t1 = *t0;
	}
	else
	{
		if (b > 0)
			q = -0.5 * (b + sqrt(discr));
		else
			q = -0.5 * (b - sqrt(discr));
		*t0 = q / a;
		t1 = c / q;
	}
	return (check_quadratic_roots(t0, &t1));
}
