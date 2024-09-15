/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:18:25 by obouayed          #+#    #+#             */
/*   Updated: 2023/12/11 17:18:25 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_hexa(unsigned int nbr)
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

static void	ft_puthexa(unsigned int nbr, char *base)
{
	if (nbr / 16)
		ft_puthexa(nbr / 16, base);
	ft_print_char(base[nbr % 16]);
}

int	ft_print_hexa_u(unsigned int nbr)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr == 0)
		return (ft_print_char('0'));
	ft_puthexa(nbr, base);
	return (len_hexa(nbr));
}

int	ft_print_hexa_l(unsigned int nbr)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr == 0)
		return (ft_print_char('0'));
	ft_puthexa(nbr, base);
	return (len_hexa(nbr));
}
