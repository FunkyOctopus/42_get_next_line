/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 08:53:32 by olgerret          #+#    #+#             */
/*   Updated: 2021/07/13 17:14:37 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*result;

	result = malloc(count * size);
	if (result == 0)
		return (0);
	i = 0;
	while (i < (count * size))
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ps;

	i = 0;
	ps = (char *)s;
	if (c == '\0')
		return (&ps[ft_strlen(ps)]);
	while (s[i] != '\0')
	{
		if (ps[i] == (char)c)
			return (&ps[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	length;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	length = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((length + 1) * sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
