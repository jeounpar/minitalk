/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:13:49 by jeounpar          #+#    #+#             */
/*   Updated: 2021/11/07 21:13:50 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join_str(char *str, const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*s1_str;
	char	*s2_str;

	s1_str = (char *)s1;
	s2_str = (char *)s2;
	i = 0;
	while (s1_str[i] != '\0')
	{
		str[i] = s1_str[i];
		i++;
	}
	j = 0;
	while (s2_str[j] != '\0')
	{
		str[i] = s2_str[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	join_str(str, s1, s2);
	return (str);
}
