/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:28:32 by soksak            #+#    #+#             */
/*   Updated: 2023/10/19 18:34:32 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ns;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	ns = (char *)malloc(sizeof(char) * len + 1);
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (s[start] && len > 0)
	{
		ns[i] = s[start];
		i++;
		start++;
		len--;
	}
	ns[i] = '\0';
	return (ns);
}
