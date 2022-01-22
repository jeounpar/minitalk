/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:41:00 by jeounpar          #+#    #+#             */
/*   Updated: 2021/11/07 12:41:01 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_str;
	unsigned char	*src_str;

	if (dest == src || n == 0)
		return (dest);
	dest_str = (unsigned char *)dest;
	src_str = (unsigned char *)src;
	if (dest < src)
		while (n--)
			*dest_str++ = *src_str++;
	else
		while (n--)
			*(dest_str + n) = *(src_str + n);
	return (dest);
}
