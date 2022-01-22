#include "minitalk.h"
#include "ft_printf/ft_printf.h"

t_msg	g_msg;

static void	handler(int signo, siginfo_t *info, void *context)
{
	int	shitf_left;

	(void)info;
	(void)context;
	if (signo == SIGUSR1)
		shitf_left = 0;
	else if (signo == SIGUSR2)
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
	struct sigaction	sig_struct;

	g_msg.c = 0;
	g_msg.size = 0;
	sig_struct.sa_sigaction = handler;
	sig_struct.sa_flags = SA_SIGINFO;
	ft_printf("Server PID : %d\n", getpid());
	sigaction(SIGUSR1, &sig_struct, 0);
	sigaction(SIGUSR2, &sig_struct, 0);
	while (1)
		pause();
	return (0);
}
