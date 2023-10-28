/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:34:15 by soksak            #+#    #+#             */
/*   Updated: 2023/10/21 21:12:29 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	f(void	*c)
{
	char *tmp = (char *)c;
	int i = 0;
	while (tmp[i])
	{
		tmp[i] = 'a';
		i++;
	}
}

int main()
{
	t_list *mylock;
	t_list *locka;
	char s[] = "Merhaba";
	char b[] = "Ben";

	mylock = ft_lstnew(s);
	locka = ft_lstnew(b);

	mylock->next = locka;
	locka->next = NULL;

	ft_lstiter(mylock, f);
	printf("%s", (char *)mylock->content);
}
