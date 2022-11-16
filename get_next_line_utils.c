/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 07:49:30 by kzerri            #+#    #+#             */
/*   Updated: 2022/11/16 15:11:51 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;

	j = 0;
	if (!s1 && !s2)
		return (NULL);
	i = (ft_strlen(s1) + ft_strlen(s2));
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	while (s1[j])
	{
		p[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		p[j + i] = s2[i];
		i++;
	}
	p[j + i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	if (!s)
		return (NULL);
	p = (char *)s;
	while (*p != (char)c)
	{
		if (!*p)
			return (NULL);
		p++;
	}
	return (p);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*p;
	size_t	j;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	while (j < i)
	{
		*(p + j) = *(s1 + j);
		j++;
	}
	*(p + j) = '\0';
	return (p);
}
