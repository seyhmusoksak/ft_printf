/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:10:36 by soksak            #+#    #+#             */
/*   Updated: 2023/10/25 00:54:09 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_puthex(unsigned int n, char format)
{

	if (n >= 16)
	{
		ft_puthex(n / 16, format);
		ft_puthex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_printchar(n + 48);
		else if (format == 'x')
			ft_printchar(n - 10 + 'a');
		else if (format == 'X')
			ft_printchar(n - 10 + 'A');
	}
}



int ft_print_hex(unsigned int n, char format)
{
	int	i;

	// Yazdırma İşlemi
	ft_puthex(n, format);
	// Uzunluk Hesabı
	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
