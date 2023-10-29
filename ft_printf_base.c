/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:36:15 by soksak            #+#    #+#             */
/*   Updated: 2023/10/29 22:15:53 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		ft_printchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_printnum(int num)
{
	int		size;
	char	*s;

	s = ft_itoa(num);
	if (!s)
		return (0);
	size = ft_printstr(s);
	free (s);
	return (size);
}

int	ft_put_unsigned(unsigned int num)
{
	int	i;

	i = 0;
	if (num >= 10)
	{
		i += ft_put_unsigned(num / 10);
		i += ft_put_unsigned(num % 10);
	}
	else
		i += ft_printchar(num + '0');
	return (i);
}

int	ft_printf_unsigned(unsigned int num)
{
	int	lenght;

	lenght = 0;
	lenght += ft_put_unsigned(num);
	return (lenght);
}
