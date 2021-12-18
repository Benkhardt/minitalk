/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:57:14 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/18 00:20:59 by dbenkhar         ###   ########.fr       */
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
#include "ft_printf/ft_printf.h"



void	send_bits(int pid, char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
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
	pid = atoi(argc[1]);
	ft_putstr_fd("PID is: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	send_bits(pid, argc[2]);
	return (0);
}
