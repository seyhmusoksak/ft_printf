/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:28:29 by soksak            #+#    #+#             */
/*   Updated: 2023/10/21 22:19:13 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*start;
	t_list	*tmp;

	if (!del)
		return ;
	start = *lst;
	while (start)
	{
		tmp = start;
		del(tmp->content);
		start = start -> next;
		free(tmp);
	}
	*lst = NULL;
}

void	del(void *a)
{
	free(a);
}
int main()
{
	t_list *a;
	t_list *b;

	a = ft_lstnew(ft_strdup("merhaba"));
	b = ft_lstnew(ft_strdup("dddddd"));

	a->next = b;
	b->next = NULL;

	ft_lstclear(&a, del);
}
