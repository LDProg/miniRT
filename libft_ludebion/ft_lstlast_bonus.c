/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:52:50 by ludebion          #+#    #+#             */
/*   Updated: 2024/11/23 19:55:22 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (lst->next == NULL)
				return (lst);
			lst = lst->next;
		}
	}
	return (NULL);
}
// int	main(void)
// {
// 	t_list *lst;
// 	t_list *last;

// 	lst = ft_lstnew("Hello");
// 	lst->next = ft_lstnew("world");
// 	last = ft_lstlast(lst);
// 	printf("Dernier élément : %s\n", (char *)last->content);
// }
