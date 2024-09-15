/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:08:23 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/30 04:25:04 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handle_signals(int signum)
{
	static int	i = 0;
	static char	c = 0;

	if (signum == SIGUSR2)
		c |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

void	config_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signals;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error concerning SIGUSR1!");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error concerning SIGUSR2!");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	__pid_t	pid;

	pid = getpid();
	if (!pid)
		return (EXIT_FAILURE);
	ft_printf("Server PID: %d\n\n", pid);
	while (1)
	{
		config_signals();
		pause();
	}
	return (EXIT_SUCCESS);
}
