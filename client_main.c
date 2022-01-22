#include "minitalk.h"
#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *nptr);

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

static void	send_msg_by_bit(int pid, char *msg, size_t msg_len)
{
	int		shift_right;
	size_t	i;

	i = 0;
	while (i <= msg_len)
	{
		shift_right = 0;
		while (shift_right < 7)
		{
			if ((msg[i] >> shift_right) & 1)
				kill (pid, SIGUSR2);
			else
				kill (pid, SIGUSR1);
			shift_right += 1;
			usleep(300);
		}
		i += 1;
	}
}

static void	confirm_from_server(int signo)
{
	ft_printf("Message Confrim\n");
}

int main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_msg_by_bit(pid, argv[2], ft_strlen(argv[2]));
		//signal(SIGUSR1, confirm_from_server);
	}
	return (0);
}