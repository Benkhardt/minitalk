/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:34:22 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/17 14:37:57 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

void	handler(int sigtype)
{
	
}

int	main (void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		ft_printf("waiting for signal... PID: %d\n", getpid());
		sleep(1);
	}
}
