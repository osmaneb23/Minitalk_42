/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_charstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:18:15 by obouayed          #+#    #+#             */
/*   Updated: 2023/12/11 17:18:15 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *c)
{
	int	i;

	i = 0;
	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (c[i])
	{
		ft_print_char(c[i]);
		i++;
	}
	return (i);
}
