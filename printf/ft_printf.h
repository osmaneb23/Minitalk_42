/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:03 by obouayed          #+#    #+#             */
/*   Updated: 2023/12/11 17:20:03 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(int c);
int	ft_print_str(char *c);
int	ft_print_percent(void);
int	ft_print_int(int nbr);
int	ft_print_ptr(void *ptr);
int	ft_print_hexa_l(unsigned int nbr);
int	ft_print_hexa_u(unsigned int nbr);
int	ft_print_unsigned(unsigned int nbr);

#endif