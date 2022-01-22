/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:08:56 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/18 22:08:56 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	find_format(char c, va_list ap)
{
	if (c == 'c')
		return (char_format(ap));
	else if (c == 'd' || c == 'i')
		return (int_format(ap));
	else if (c == 's')
		return (string_format(ap));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else if (c == 'p')
		return (pointer_format(ap));
	else if (c == 'x' || c == 'X' || c == 'u')
		return (hex_format(ap, c));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_start(ap, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			len++;
			ft_putchar_fd(str[i], 1);
		}
		else
		{
			len += find_format(str[i + 1], ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
