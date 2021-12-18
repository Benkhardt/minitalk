/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:57:14 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/18 17:20:38 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

/*
32	= 0x0020 = 0000 0000 0010 0000 // Space, first valid char from ascii
.
.
.
127	= 0x007F = 0000 0000 0111 1111

c = 99 = 0x0063 = 0000 0000 0110 0011
* =  1 = 0x0001 = 0000 0000 0000 0001
*/

// if ((c ) & 1)

void	send_char(int pid, int c)
{
	int shift;

	shift = 0;
	while (shift < 7)
	{
		if ((c >> shift) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		shift++;
		usleep(100);
	}
}

void	send_str(int pid, char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		send_char(pid, (int)str[i]);
		i++;
	}
}



int main(int argv, char *argc[])
{
	int pid;

	if (argv != 3)
	{
		ft_putstr_fd("Usage: ./client [server_pid] [str_to_send]", 1);
		return (-1);
	}
	pid = atoi(argc[1]); // has to be changed for final submit...
	ft_putstr_fd("PID is: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	send_str(pid, argc[2]);
	return (0);
}
