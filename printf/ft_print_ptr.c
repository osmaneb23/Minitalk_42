/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:18:54 by obouayed          #+#    #+#             */
/*   Updated: 2023/12/11 17:18:54 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_ptr(size_t nbr)
{
	int	i;

	i = 1;
	while (nbr / 16)
	{
		i++;
		nbr = nbr / 16;
	}
	return (i);
}

static void	ft_putptr(size_t ptr)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr / 16)
		ft_putptr(ptr / 16);
	ft_print_char(base[ptr % 16]);
}

int	ft_print_ptr(void *ptr)
{
	if (!ptr)
		return (ft_print_str("(nil)"));
	ft_print_str("0x");
	ft_putptr((size_t)ptr);
	return (2 + len_ptr((size_t)ptr));
}
