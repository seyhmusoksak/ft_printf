/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:06:58 by soksak            #+#    #+#             */
/*   Updated: 2023/10/11 19:42:11 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	ch;

	i = 0;
	tmp = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (tmp[i] == ch)
			return (&tmp[i]);
		i++;
	}
	return (NULL);
}
