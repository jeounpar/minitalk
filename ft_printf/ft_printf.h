/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:53:04 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/21 19:53:04 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		string_format(va_list ap);
int		char_format(va_list ap);
int		int_format(va_list ap);
int		hex_format(va_list ap, char c);
int		pointer_format(va_list ap);
char	*ft_itopointer(unsigned long long n, char *base);
char	*ft_hextoa(long long n, char *base);

#endif