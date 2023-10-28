/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 01:46:11 by soksak            #+#    #+#             */
/*   Updated: 2023/10/21 18:46:32 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	i;
	char	*dest;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * s_len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}



char f(unsigned int index, char c) {

    // İndeks 5 ile 10 arasındaysa, karakteri '?' ile değiştir
    if (index >= 5 && index <= 10) {
        return '?';
    }
    return c; // Diğer karakterler aynı kalsın
}





int main()
{
	char *dest = ft_strdup("Merhaba ben");

	dest = ft_strmapi(dest, f);

	printf("%s", dest);
}
