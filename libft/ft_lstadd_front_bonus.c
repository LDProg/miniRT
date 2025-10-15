/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:31:17 by ludebion          #+#    #+#             */
/*   Updated: 2024/11/24 02:37:09 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

// int	main(void)
// {
// 	t_list	**lst;
// 	t_list	*lst_first;
// 	int		count;

// 	count = 0;
// 	lst = ft_calloc(1, sizeof(t_list));
// 	*lst = ft_lstnew("Hello");
// 	(*lst)->next = ft_lstnew("world");
// 	lst_first = *lst;
// 	printf("Liste avant ajout au début : \n\n");
// 	while (*lst)
// 	{
// 		printf("Mon élément n [%d] : %s\n", count, (char *)(*lst)->content);
// 		count++;
// 		lst = &(*lst)->next;
// 	}
// 	lst = &lst_first;
// 	printf("\nListe après ajout au début : \n\n");
// 	ft_lstadd_front(lst, ft_lstnew("this is Luca"));
// 	count = 0;
// 	while (*lst)
// 	{
// 		printf("Mon élément n [%d] : %s\n", count, (char *)(*lst)->content);
// 		count++;
// 		*lst = (*lst)->next;
// 	}
// }
