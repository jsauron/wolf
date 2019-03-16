/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 10:14:05 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/16 10:14:07 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isw(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static char		*ft_transfert_trim(char *str, char *s, int i, int temp)
{
	if (!(str = (char *)ft_memalloc_lt(sizeof(char) * (i - (i - temp)))))
		return (0);
	i = 0;
	while (i < temp)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	str = 0;
	if (!s)
		return (0);
	while (s && (ft_isw(*s)))
		s++;
	while (s[i])
	{
		if (!ft_isw(s[i]))
			temp = i + 1;
		i++;
	}
	str = ft_transfert_trim(str, (char *)s, i, temp);
	return ((char *)str);
}
