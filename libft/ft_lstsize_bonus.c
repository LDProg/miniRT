/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:49:56 by ludebion          #+#    #+#             */
/*   Updated: 2024/11/23 19:52:40 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (lst)
	{
		while (lst)
		{
			size++;
			lst = lst->next;
		}
	}
	return (size);
}

// int	main(void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew("Hello");
// 	lst->next = ft_lstnew("world");
// 	printf("Nombre d'élément : %d\n", ft_lstsize(lst));
// }
