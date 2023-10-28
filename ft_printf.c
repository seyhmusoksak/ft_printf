/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:41:01 by soksak            #+#    #+#             */
/*   Updated: 2023/10/25 01:18:40 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf_base.c"
#include "ft_printf_hex.c"

int	ft_findformat(va_list args, char format)
{
	int	lenght;

	lenght = 0;
	if (format == 'c')
		lenght += ft_printchar(va_arg(args, int));
	else if (format == 's')
		lenght += ft_printstr(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		lenght += ft_printnumber(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		lenght += ft_print_hex(va_arg(args, unsigned int), format);
	return (lenght);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		lenght;
	va_list	args;

	i = 0;
	lenght = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				ft_printchar('%');
			else
				lenght += ft_findformat(args, format[i + 1]);
			i++;
		}
		else
			lenght += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (lenght);
}
