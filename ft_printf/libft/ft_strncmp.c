/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:15:18 by jeounpar          #+#    #+#             */
/*   Updated: 2021/11/06 00:15:19 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_str;
	unsigned char	*s2_str;

	i = 0;
	s1_str = (unsigned char *)s1;
	s2_str = (unsigned char *)s2;
	while (n--)
	{
		if (s1_str[i] != s2_str[i] || s1_str[i] == '\0'
			|| s2_str[i] == '\0')
			return (s1_str[i] - s2_str[i]);
		i++;
	}
	return (0);
}
