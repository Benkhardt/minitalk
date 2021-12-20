/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:41:17 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/20 11:21:40 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"

# ifndef S_TIMEOUT
#  define S_TIMEOUT 150
# endif

typedef struct h_bits
{
	int	c;
	int	size;
	int	signal;
	int	count;
	int	pid;
}				t_bits;

void	handler(int sig);

#endif
