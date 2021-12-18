/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:34:22 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/17 21:52:20 by dbenkhar         ###   ########.fr       */
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

static g_bits a;

// 30 = 0x001E =	0000 0000 0001 1110			31 = 0x001F = 	0000 0000 0001 1111
// 				0000 0000 0000 0001							0000 0000 0000 0001
// 			&	0000 0000 0000 0000						&	0000 0000 0000 0001

void	handler(int sig)
{
	a.c = sig & 1;
	if (!a.c)
		ft_putstr_fd("SIGUSR1 received\n", 1);
	else
		ft_putstr_fd("SIGUSR2 received\n", 1);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	a.c = 0;
	a.size = 0;
	ft_putstr_fd("Waiting for Signal\n", 1);
	ft_putstr_fd("pid is ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, handler); // 0
		signal(SIGUSR2, handler); // 1
		pause();
	}
}
