/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:06:16 by soksak            #+#    #+#             */
/*   Updated: 2023/10/21 23:32:59 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libft.h"

static char	*ft_createstr(const char *s, size_t len)
{
	size_t	i;
	char	*splitted;

	if (len == 0)
		return (NULL);
	splitted = (char *)malloc(sizeof(char) * len + 1);
	if (!splitted)
		return (NULL);
	i = 0;
	while (i < len)
	{
		splitted[i] = s[i];
		i++;
	}
	splitted[i] = '\0';
	return (splitted);
}

static	size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || \
			(s[i] == c && s[i + 1] != c && s[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	save;
	char	**dest;

	dest = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_countword(s, c) && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		save = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		dest[j] = ft_createstr(&s[save], i - save);
		j++;
	}
	dest[j] = NULL;
	return (dest);
}


int main()
{
    char **as;
    char *s;

    s = ft_strdup("merhaba ben 42");

    as = ft_split(s, ' ');

    int i = 0;

    printf("%s", s);
    while (as[i] != NULL) {
        printf("%s", as[i]);
        free(as[i]);  // Her parçayı serbest bırak
        i++;
    }

    free(as);  // Parça dizisini serbest bırak
    free(s);   // s işaretçisini serbest bırak
}
