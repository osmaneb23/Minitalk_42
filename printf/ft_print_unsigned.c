/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:19:03 by obouayed          #+#    #+#             */
/*   Updated: 2023/12/11 17:19:03 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_nbr(unsigned long n)
{
	int	compteur;

	compteur = 1;
	while (n > 9)
	{
		n = n / 10;
		compteur++;
	}
	return (compteur);
}

static char	*ft_itoa(unsigned int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	i = len_nbr(nbr);
	str = (char *)malloc(len_nbr(nbr) + 1);
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[i - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	nbr = n;
	str[len_nbr(nbr)] = 0;
	return (str);
}

int	ft_print_unsigned(unsigned int nbr)
{
	int		i;
	char	*num;

	num = ft_itoa(nbr);
	i = ft_print_str(num);
	free(num);
	return (i);
}
