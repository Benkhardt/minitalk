/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:57:14 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/17 02:24:39 by dbenkhar         ###   ########.fr       */
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

int main(int argv, char *argc[])
{
	int pid = atoi(argc[1]);
	int rtn = kill(pid, 30);
	printf("pid is: %d\n kill rtn is: %d\n", pid, rtn);
	return (0);
}
