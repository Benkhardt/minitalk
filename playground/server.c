/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:34:22 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/19 17:18:40 by dbenkhar         ###   ########.fr       */
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
// static int count; // for testing

// 30 = 0x001E =	0000 0000 0001 1110			31 = 0x001F = 	0000 0000 0001 1111
// 				0000 0000 0000 0001							0000 0000 0000 0001
// 			&	0000 0000 0000 0000						&	0000 0000 0000 0001

void	handler(int sig)
{
	sig = sig & 1;
	if (!sig)
	{
		a.c += sig << a.size;
		// ft_putstr_fd("0 received\n", 1); 
	}
	else
	{
		 a.c += sig << a.size;
		// ft_putstr_fd("1 received\n", 1);
	}
	a.size++;
	if (a.size == 7)
	{
		if ((char)a.c == '\0')
		{
			ft_putchar_fd('\n', 1);
			a.c = 0;
			a.size = 0;
			return;
		}
		ft_putchar_fd((char)a.c, 1);
		a.c = 0;
		a.size = 0;
	}
	// count++;
	//ft_putstr_fd("Signal counter: ", 1);
	//ft_putnbr_fd(count, 1); // .. same (testing)
	//ft_putstr_fd("\n", 1);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	a.c = 0;
	a.size = 0;
	// count = 0;
	ft_putstr_fd("Waiting for Signal\n", 1);
	ft_putstr_fd("pid is: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, handler); // 0
		signal(SIGUSR2, handler); // 1
		pause();
	}
}
