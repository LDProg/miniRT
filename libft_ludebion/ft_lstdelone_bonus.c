/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebion <ludebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:23:13 by ludebion          #+#    #+#             */
/*   Updated: 2024/11/24 02:44:42 by ludebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del && lst)
	{
		free(lst);
		return ;
	}
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	**lst;

// 	lst = NULL;
// 	*lst = ft_lstnew("Hello");
// 	(*lst)->next = ft_lstnew("world");
// 	printf("Liste avant suppression : \n\n");
// 	while (*lst)
// 	{
// 		printf("Mon élément : %s\n", (char *)(*lst)->content);
// 		*lst = (*lst)->next;
// 	}
// 	printf("\nListe après suppression : \n\n");
// 	ft_lstdelone(*lst, del);
// 	while (*lst)
// 	{
// 		printf("Mon élément : %s\n", (char *)(*lst)->content);
// 		*lst = (*lst)->next;
// 	}
// }

// int	main(void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew("Hello");
// 	lst->next = ft_lstnew("world");
// 	printf("Liste avant suppression : \n\n");
// 	while (lst)
// 	{
// 		printf("Mon élément : %s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("\nListe après suppression : \n\n");
// 	ft_lstdelone(lst, del);
// 	while (lst)
// 	{
// 		printf("Mon élément : %s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }
