/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:41:17 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/12/19 17:18:50 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"

typedef struct h_bits
{
	int	c;
	int	size;
	int signal;
	int count;

}	g_bits;

extern int b;

void	handler(int sig);

#endif
