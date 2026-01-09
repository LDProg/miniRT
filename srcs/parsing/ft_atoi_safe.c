/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:17:02 by ludebion          #+#    #+#             */
/*   Updated: 2026/01/08 15:59:32 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	check_int_overflow(int n, int digit, int sign)
{
	if (sign > 0)
	{
		if (n > (INT_MAX - digit) / 10)
			return (0);
	}
	else
	{
		if (n > (-(INT_MIN + digit)) / 10)
			return (0);
	}
	return (1);
}

int	ft_atoi_safe(const char *nptr)
{
	int	i;
	int	n;
	int	sign;
	int	digit;

	i = 0;
	n = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		++i;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		digit = nptr[i] - '0';
		if (!check_int_overflow(n, digit, sign))
			return (-1);
		n = n * 10 + digit;
		++i;
	}
	return (sign * n);
}
