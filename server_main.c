/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:48:47 by jeounpar          #+#    #+#             */
/*   Updated: 2022/02/06 13:36:46 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"

t_msg	g_msg;

void	handler(int signo)
{
	int	shitf_left;

	if (signo == SIGUSR1)
		shitf_left = 0;
	else
		shitf_left = 1;
	g_msg.c += ((shitf_left & 1) << g_msg.size);
	g_msg.size += 1;
	if (g_msg.size == 7)
	{
		ft_printf("%c", g_msg.c);
		if (!g_msg.c)
			ft_printf("\n");
		g_msg.c = 0;
		g_msg.size = 0;
	}
}

int	main(void)
{
	g_msg.c = 0;
	g_msg.size = 0;
	ft_printf("Server PID : %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
