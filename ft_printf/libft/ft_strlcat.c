/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:14:28 by jeounpar          #+#    #+#             */
/*   Updated: 2021/11/06 00:14:29 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	idx;

	i = 0;
	idx = 0;
	while (dest[i] && i < size)
		i++;
	while (src[idx] && (i + idx + 1) < size)
	{
		dest[i + idx] = src[idx];
		idx++;
	}
	if (i < size)
		dest[i + idx] = '\0';
	return (i + my_strlen(src));
}
