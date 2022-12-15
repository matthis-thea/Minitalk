/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:16:45 by mthea             #+#    #+#             */
/*   Updated: 2022/12/15 15:39:06 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ft_printf/ft_printf.h"

void ft_bits_into_char(int sig) 
{
	static char	c = 0;
	static int	count = 0;

	c <<= 1;
	if (sig == SIGUSR1)
		c+=1;
	count++;
	if (count == 8)
	{
		write(1, &c, 1);
		count = 0;
		c = 0;
	}
}

int main(void)
{
	int	pid;
	pid = getpid();
	ft_printf("Server lanched\n");
	ft_printf("Here is the PID: %d\n", pid);
	signal(SIGUSR2, ft_bits_into_char);
	signal(SIGUSR1, ft_bits_into_char);
	while (1)
	{
		continue;
	}
	return (0);
}