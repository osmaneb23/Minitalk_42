/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:19:44 by obouayed          #+#    #+#             */
/*   Updated: 2023/12/11 17:19:44 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(const char *format, va_list args)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (*format == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (*format == 'p')
		len += ft_print_ptr(va_arg(args, void *));
	else if (*format == 'i' || *format == 'd')
		len += ft_print_int(va_arg(args, int));
	else if (*format == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		len += ft_print_hexa_l(va_arg(args, int));
	else if (*format == 'X')
		len += ft_print_hexa_u(va_arg(args, int));
	else if (*format == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_print_format(&str[i], args);
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
