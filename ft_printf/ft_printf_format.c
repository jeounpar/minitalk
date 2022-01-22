/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:30:30 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/21 23:45:49 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	string_format(va_list ap)
{
	char	*str;
	char	*rst;
	int		len;

	len = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		rst = "(null)";
	else
		rst = ft_strdup(str);
	len += ft_putstr_fd(rst, 1);
	if (str != NULL)
		free(rst);
	return (len);
}

int	char_format(va_list ap)
{
	ft_putchar_fd(va_arg(ap, int), 1);
	return (1);
}

int	int_format(va_list ap)
{
	int		n;
	int		len;
	char	*str;

	len = 0;
	n = va_arg(ap, int);
	str = ft_itoa(n);
	len = ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	pointer_format(va_list ap)
{
	char				*str;
	unsigned long long	n;
	int					len;

	len = 0;
	n = va_arg(ap, unsigned long long);
	if (n != 0)
		str = ft_itopointer(n, "0123456789abcdef");
	else
		str = ft_strdup("0");
	len += ft_putstr_fd("0x", 1);
	len += ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	hex_format(va_list ap, char c)
{
	char	*str;
	int		len;

	len = 0;
	if (c == 'x')
		str = ft_hextoa(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		str = ft_hextoa(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else
		str = ft_hextoa(va_arg(ap, unsigned int), "0123456789");
	len = ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
