/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:44 by obouayed          #+#    #+#             */
/*   Updated: 2024/07/18 19:43:09 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// Function to verify the PID format (digits only)
int	verif_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] <= '9' && pid[i] >= '0')
			i++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// Function to verify the number of arguments and the PID format
void	verif_args(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Invalid number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	if (verif_pid(av[1]) == EXIT_FAILURE)
	{
		ft_printf("Invalid server PID format!\n");
		exit(EXIT_FAILURE);
	}
}

// Function to convert a string to an integer
int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!nptr[0])
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}

/*
Function to send a message to the server by sending signals:
- We consider each ASCII digit representing a character, as a byte.
- Mask is a variable that contains a 1 in the bit position that 
we want to check (starting by the most significant bit).
- We check if the bit at the same position for the mask and
the character is 1 or 0 by using the bitwise AND operator
(return 1 if both bits are 1).
- If it is 1, we send a SIGUSR2 signal.
- If it is 0, we send a SIGUSR1 signal.
- We pass to the next bit by decrementing bits_shift by 1.
- We wait for 600 microseconds.
- We repeat the process until we reach the end of the message.
*/

void	send_chars_as_signals(char *message, int pid)
{
	char	c;
	int		i;
	int		mask;
	int		bits_shift;

	i = 0;
	while (message[i])
	{
		bits_shift = 7;
		c = message[i];
		while (bits_shift >= 0)
		{
			mask = 1 << bits_shift;
			if ((c & mask) > 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bits_shift--;
			usleep(600);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	__pid_t	pid_server;

	verif_args(ac, av);
	pid_server = ft_atoi(av[1]);
	send_chars_as_signals(av[2], pid_server);
	return (EXIT_SUCCESS);
}
