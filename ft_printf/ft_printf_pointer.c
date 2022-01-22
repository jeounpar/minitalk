/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:30:23 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/21 23:46:25 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	get_len(unsigned long long n, int base_len)
{
	int	cnt;

	cnt = 0;
	while (1)
	{
		cnt++;
		if (n / base_len == 0)
			break ;
		n /= base_len;
	}
	return (cnt);
}

static void	str_base_to(unsigned long long n, char *base, char *str, int size)
{
	int					i;
	int					neg;
	int					len;
	unsigned long long	tmp;

	len = ft_strlen(base);
	i = 0;
	neg = 1;
	while (i < size)
	{
		tmp = n % len;
		str[size - i - neg] = base[tmp];
		n = n / len;
		i++;
	}
	str[i] = '\0';
}

char	*ft_itopointer(unsigned long long n, char *base)
{
	int		size;
	char	*str;

	size = get_len(n, ft_strlen(base));
	str = (char *)malloc((size + 3) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str_base_to(n, base, str, size);
	return (str);
}
