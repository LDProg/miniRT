/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:41:03 by ludebion          #+#    #+#             */
/*   Updated: 2024/11/24 03:57:46 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

// void	f(void *content)
// {
// 	char	*str;

// 	str = (char *)(content);
// 	ft_memcpy(str, "Hey", 5);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*lst_first;
// 	int		count;

// 	lst = ft_calloc(1, sizeof(t_list));
// 	lst = ft_lstnew(ft_strdup("Hello"));
// 	lst_first = lst;
// 	lst->next = ft_lstnew(ft_strdup("world"));
// 	count = 0;
// 	printf("Liste avant modif : \n\n");
// 	while (lst)
// 	{
// 		printf("Mon élément n [%d] : %s\n", count, (char *)lst->content);
// 		count++;
// 		lst = lst->next;
// 	}
// 	lst = lst_first;
// 	printf("\nListe après modif : \n\n");
// 	ft_lstiter(lst, f);
// 	count = 0;
// 	while (lst)
// 	{
// 		printf("Mon élément n [%d] : %s\n", count, (char *)lst->content);
// 		count++;
// 		lst = lst->next;
// 	}
// }
