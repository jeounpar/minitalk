/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:50:16 by jeounpar          #+#    #+#             */
/*   Updated: 2021/11/06 17:50:18 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	cc;
	char			*tmp;
	int				i;

	i = ft_strlen(s);
	tmp = (char *)s;
	cc = (unsigned char)c;
	while (i > 0)
	{
		if (tmp[i] == cc)
			return (&tmp[i]);
		i--;
	}
	if (tmp[i] == cc)
		return (tmp);
	return (NULL);
}
