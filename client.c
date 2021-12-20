/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:57:14 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/20 16:09:48 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>
#include <signal.h>

/*
** The idea is to break everything down to 
** only 0's and 1's. Sending then char by char
** to 'server' with only UNIX signals SIGUSR1 &
** SIGUSR2. I use bitwise operators to trans-
** late ASCII integers to binary and then 
** submit every 0 or 1 from right to left
** using shift operator for doing the trick.
*/

// send_char()
// Sending char by char using bitwise operators.

void	send_char(int pid, int c)
{
	int	shift;

	shift = 0;
	ft_putstr_fd("(binary: ", 1);
	while (shift < 7)
	{
		if ((c >> shift) & 1)
		{
			ft_putchar_fd('1', 1);
			kill(pid, SIGUSR2);
		}
		else
		{
			ft_putchar_fd('0', 1);
			kill(pid, SIGUSR1);
		}
		shift++;
		usleep(S_TIMEOUT);
	}
}

// send_str()
// Give over every single char to send_char().

void	send_str(int pid, char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		ft_putstr_fd("Sending char: ", 1);
		ft_putchar_fd(str[i], 1);
		ft_putchar_fd(' ', 1);
		send_char(pid, (int)str[i]);
		ft_putstr_fd(")\n", 1);
		i++;
	}
}

// In my main we check for correct usage.

int	main(int argv, char *argc[])
{
	int	pid;

	if (argv != 3)
	{
		ft_putstr_fd("Usage: ./client [server_pid] [str_to_send]", 1);
		return (-1);
	}
	pid = ft_atoi(argc[1]);
	ft_putstr_fd("PID is: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	send_str(pid, argc[2]);
	return (0);
}
