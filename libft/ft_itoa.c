/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 03:06:42 by soksak            #+#    #+#             */
/*   Updated: 2023/10/24 23:41:52 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_calculate(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	int		sign;
	char	*dest;

	i = ft_calculate(n);
	nb = n;
	sign = 1;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	dest[i--] = '\0';
	if (nb < 0)
	{
		sign = -1;
		nb *= -1;
	}
	while (i >= 0)
	{
		dest[i--] = '0' + (nb % 10);
		nb = nb / 10;
	}
	if (sign == -1)
		dest[0] = '-';
	return (dest);
}
