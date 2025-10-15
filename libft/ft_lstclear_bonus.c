/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:27:38 by ludebion          #+#    #+#             */
/*   Updated: 2024/11/24 03:11:34 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				next = (*lst)->next;
				ft_lstdelone(*lst, del);
				*lst = next;
			}
		}
		lst = NULL;
	}
}

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	**lst;
// 	t_list	*lst_first;
// 	int		count;

// 	lst = ft_calloc(1, sizeof(t_list));
// 	*lst = ft_lstnew(ft_strdup("Hello"));
// 	(*lst)->next = ft_lstnew(ft_strdup("world"));
// 	lst_first = *lst;
// 	count = 0;
// 	printf("Liste avant clear : \n\n");
// 	while (*lst)
// 	{
// 		printf("Mon élément n [%d] : %s\n", count, (char *)(*lst)->content);
// 		*lst = (*lst)->next;
// 	}
// 	printf("\nListe après clear : \n\n");
// 	ft_lstclear(lst, del);
// 	while (*lst)
// 	{
// 		printf("Mon élément n [%d] : %s\n", count, (char *)(*lst)->content);
// 		*lst = (*lst)->next;
// 	}
// }
