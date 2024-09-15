/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:22:38 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/29 20:28:17 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Define MINITALK_H to prevent multiple inclusions
#ifndef MINITALK_H
# define MINITALK_H

// For printf function
# include "../printf/ft_printf.h"
// For signal handling functions (SIGUSR1, SIGUSR2)
# include <signal.h>
// For malloc, free, and exit functions
# include <stdlib.h>
// For write, getpid, pause, sleep functions
# include <unistd.h>

#endif
