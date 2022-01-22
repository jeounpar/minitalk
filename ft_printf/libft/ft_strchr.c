/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:52:52 by jeounpar          #+#    #+#             */
/*   Updated: 2021/11/06 16:52:54 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;
	char			*tmp;
	int				i;

	i = 0;
	tmp = (char *)s;
	cc = (unsigned char)c;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == cc)
			return (&tmp[i]);
		i++;
	}
	if (tmp[i] == cc)
		return (&tmp[i]);
	return (0);
}
