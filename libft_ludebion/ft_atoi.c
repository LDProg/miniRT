/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:28:30 by ludebion          #+#    #+#             */
/*   Updated: 2024/11/16 18:37:04 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * n);
}

// int	main(void)
// {
// 	char	s1[] = "0";
// 	char	s2[] = "-69";
// 	char	s3[] = "+69";
// 	char	s4[] = "--69";
// 	char	s5[] = "++69";
// 	char	s6[] = "-2147483648";
// 	char	s7[] = "2147483647";
// 	char	s8[] = "    \t\n\v\f\r69";

// 	printf("Valeur attendue 0 : %d\n", ft_atoi(s1));
// 	printf("Valeur attendue -69 : %d\n", ft_atoi(s2));
// 	printf("Valeur attendue 69 : %d\n", ft_atoi(s3));
// 	printf("Valeur attendue 0 : %d\n", ft_atoi(s4));
// 	printf("Valeur attendue 0 : %d\n", ft_atoi(s5));
// 	printf("Valeur attendue -2147483648 : %d\n", ft_atoi(s6));
// 	printf("Valeur attendue : 2147483647 %d\n", ft_atoi(s7));
// 	printf("Valeur attendue 69 : %d\n", ft_atoi(s8));
// }
