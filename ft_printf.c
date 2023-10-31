/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:26:33 by soksak            #+#    #+#             */
/*   Updated: 2023/10/31 17:34:54 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_findformat(va_list args, char format)
{
	int	lenght;

	lenght = 0;
	if (format == 'c')
		lenght += ft_printchar(va_arg(args, int));
	else if (format == 's')
		lenght += ft_printstr(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		lenght += ft_printnum(va_arg(args, int));
	else if (format == 'p')
		lenght += ft_printf_ptr(va_arg(args, unsigned long long));
	else if (format == 'x' || format == 'X')
		lenght += ft_printf_hex(va_arg(args, unsigned int), format);
	else if (format == 'u')
		lenght += ft_printf_unsigned(va_arg(args, unsigned int));
	else if (format == '%')
		lenght += ft_printchar('%');
	else
		lenght += ft_printchar(format);
	return (lenght);
}

int	ft_printf(const char *format, ...)
{
	int		lenght;
	int		i;
	va_list	args;

	lenght = 0;
	i = 0;
	va_start(args, format);
	while (format [i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			lenght += ft_findformat(args, format[i + 1]);
			i++;
		}
		else if (format[i] != '%')
			lenght += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (lenght);
}
