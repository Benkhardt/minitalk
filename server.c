/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:34:22 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/20 11:20:31 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

/*
** Server waits for incoming signals using
** an endless loop. The Server is only
** able to recognize 2 signals, SIGUSR1
** and SIGUSR2. Server will then give 
** over these signals to the handler()
** where a char is build and gets printed
** by a libft function after we received 7
** signals. This is pretty much basic and 
** can handle clients only in a row, not
** simultaneously.
*/

// we need one global struct to make it accessable 
// for the handler setting it to 0 when
// needed.

static t_bits	g_a;

// handler()
// handler() is translating 7 received signals
// into a char and puts it to standard out.

void	handler(int sig)
{
	sig = sig & 1;
	if (!sig)
		g_a.c += sig << g_a.size;
	else
		g_a.c += sig << g_a.size;
	g_a.size++;
	if (g_a.size == 7)
	{
		if ((char)g_a.c == '\0')
		{
			ft_putchar_fd('\n', 1);
			g_a.c = 0;
			g_a.size = 0;
			return ;
		}
		ft_putchar_fd((char)g_a.c, 1);
		g_a.c = 0;
		g_a.size = 0;
	}
}

// main() is waiting for signals and will
// use handler() for translating.

int	main(void)
{
	g_a.pid = getpid();
	g_a.c = 0;
	g_a.size = 0;
	ft_putstr_fd("Waiting for Signal\n", 1);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(g_a.pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
}
