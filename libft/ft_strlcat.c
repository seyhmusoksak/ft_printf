/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:29:28 by soksak            #+#    #+#             */
/*   Updated: 2023/10/18 00:36:59 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	len;
	size_t	j;

	if (!dest && !src)
		return (0);
	len = ft_strlen(dest) + ft_strlen(src);
	if (dest_size <= ft_strlen(dest))
		return (dest_size + ft_strlen(src));
	j = ft_strlen(dest);
	i = 0;
	while ((i < dest_size - (len - (ft_strlen(src))) - 1) && src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (len);
}
