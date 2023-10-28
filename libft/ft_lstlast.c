/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:37:46 by soksak            #+#    #+#             */
/*   Updated: 2023/10/21 22:12:50 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}


int main()
{
	 t_list *a;
	 t_list *b;
	 t_list *c;
	 t_list *d;

	a = ft_lstnew("merhaba");
	b = ft_lstnew("baba");
	c = ft_lstnew("aaaa");

	a->next = b;
	b->next = c;

	d = ft_lstlast(a);

	printf("%s", (char *)d->content);


}
