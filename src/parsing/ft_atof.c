/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:13:14 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/11 14:00:15 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <float.h>
#include <stdio.h>
#include "minirt.h"

float	ft_atof(const char *nptr)
{
	float	result;
	float	decimal;
	int	inv;

	result = 0.0;
	decimal = 0.1;
	inv = 1;
	while (*nptr == ' ' || ((*nptr >= 9 && *nptr <= 13) && *nptr != 0))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			inv = -inv;
		nptr++;
	}
	while ((*nptr >= '0' && *nptr <= '9') && *nptr != '\0')
	{
		result = (result * 10) + (*nptr - '0');
		if (result > FLT_MAX + 1 && inv == -1)
			return (FLT_MIN);
		else if (result > FLT_MAX && inv == 1)
			return (FLT_MAX);
		nptr++;
	}
	printf(YELLOW"result atof = %g\n"RESET, result * inv);
	if (*nptr == '.')
		nptr++;
	while ((*nptr >= '0' && *nptr <= '9') && *nptr != '\0')
	{
		result += (*nptr - '0') * decimal;
		printf(RED"result atof = %g\n"RESET, result * inv);
		decimal *= 0.1;
		nptr++;
	}
	printf(GREEN"result atof = %g\n"RESET, result * inv);
	return (result * inv);
}
