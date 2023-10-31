/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:27:43 by soksak            #+#    #+#             */
/*   Updated: 2023/10/31 17:35:40 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(unsigned long long num)
{
	int	i;

	i = 0;
	if (num >= 16)
	{
		i += ft_put_ptr(num / 16);
		i += ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			i += ft_printchar(num + 48);
		else
			i += ft_printchar(num - 10 + 'a');
	}
	return (i);
}

int	ft_printf_ptr(unsigned long long num)
{
	int	lenght;

	lenght = 0;
	lenght += write(1, "0x", 2);
	if (num == 0)
		lenght += write(1, "0", 1);
	else
	{
		lenght += ft_put_ptr(num);
	}
	return (lenght);
}
