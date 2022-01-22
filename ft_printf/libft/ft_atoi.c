/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:28:32 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/18 22:08:37 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

static int	get_result(char *str, int i, long long result, int neg)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = str[i] - '0' + result * 10;
		i++;
	}
	if (result > 2147483647 && neg == 1)
		return (-1);
	if (result > 2147483648 && neg == -1)
		return (0);
	return (result * neg);
}

int	ft_atoi(const char *nptr)
{
	char		*str;
	int			neg;
	int			cnt;
	int			i;
	long long	result;

	str = (char *)nptr;
	neg = 1;
	cnt = 0;
	result = 0;
	i = 0;
	while (my_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		cnt++;
		if (cnt > 1)
			return (0);
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	return (get_result(str, i, result, neg));
}
