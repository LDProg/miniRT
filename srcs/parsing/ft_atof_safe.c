/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:42:20 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/24 18:11:29 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

static double	handle_integer_part(const char *str, size_t *i, int sign)
{
	double	res;

	res = 0;
	if (!(str[*i] >= '0' && str[*i] <= '9'))
		return (NAN);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (isinf(res * 10 + (str[*i] - '0')))
		{
			if (sign == 1)
				return (INFINITY);
			return (-INFINITY);
		}
		res = res * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (res);
}

static double	handle_decimal_part(const char *str, size_t *i, double res,
		int sign)
{
	double	factor;

	if (str[*i] == '\0')
		return (res);
	if (str[*i] != '.' || !(str[(*i) + 1] >= '0' && str[(*i) + 1] <= '9'))
		return (NAN);
	(*i)++;
	factor = 0.1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (isinf(res + (str[*i] - '0') * factor))
		{
			if (sign == 1)
				return (INFINITY);
			return (-INFINITY);
		}
		res += (str[*i] - '0') * factor;
		factor /= 10;
		(*i)++;
	}
	return (res);
}

double	ft_atof_safe(const char *str)
{
	size_t	i;
	int		sign;
	double	res;

	if (!str || !*str)
		return (NAN);
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = handle_integer_part(str, &i, sign);
	if (isinf(res) || isnan(res))
		return (res);
	res = handle_decimal_part(str, &i, res, sign);
	if (isinf(res) || isnan(res))
		return (res);
	if (str[i] != '\0')
		return (NAN);
	return (res * sign);
}

bool	check_atof(double a)
{
	return (!isinf(a) && !isnan(a));
}

bool	check_tuple(double x, double y, double z)
{
	return (!isinf(x) && !isinf(y) && !isinf(z) && !isnan(x) && !isnan(y)
		&& !isnan(z));
}
