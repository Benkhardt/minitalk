/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:34:22 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/17 02:20:34 by dbenkhar         ###   ########.fr       */
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
	ft_printf("got signal SIGUSRtest: %d\n", sigtype);
}

int	main (void)
{
	signal(30, handler);
	signal(31, handler);
	while (1)
	{
		ft_printf("waiting for signal... PID: %d\n", getpid());
		sleep(1);
	}
}