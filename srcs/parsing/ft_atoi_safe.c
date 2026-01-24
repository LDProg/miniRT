/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:17:02 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/24 18:38:46 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdbool.h>

static bool	check_int_overflow(int n, int digit, int sign)
{
	if (sign > 0)
	{
		if (n > (INT_MAX - digit) / 10)
			return (false);
	}
	else
	{
		if (n > (-(INT_MIN + digit)) / 10)
			return (false);
	}
	return (true);
}

bool	ft_atoi_safe(const char *nptr, int32_t *out)
{
	int	i;
	int	n;
	int	sign;

	if (!nptr || !out)
		return (false);
	i = 0;
	n = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(nptr[i]))
		return (false);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (!check_int_overflow(n, nptr[i] - '0', sign))
			return (false);
		n = n * 10 + (nptr[i++] - '0');
	}
	*out = sign * n;
	return (nptr[i] == '\0');
}
