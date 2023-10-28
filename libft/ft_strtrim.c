/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:03:15 by soksak            #+#    #+#             */
/*   Updated: 2023/10/14 23:18:55 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;
	char	*dest;

	if (s != NULL && set != NULL)
	{
		start = 0;
		end = ft_strlen(s);
		while (ft_strchr(set, s[start]) && s[start])
			start++;
		while (s[end - 1] && ft_strchr(set, s[end - 1]) && end > start)
			end--;
		dest = (char *)malloc(sizeof(char) * end - start + 1);
		if (!dest)
			return (NULL);
		ft_strlcpy(dest, &s[start], end - start + 1);
		return (dest);
	}
	return (NULL);
}
