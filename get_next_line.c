/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 08:53:32 by olgerret          #+#    #+#             */
/*   Updated: 2021/07/13 14:16:43 by olgerret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (s == 0)
		return (0);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		result[0] = '\0';
		return (result);
	}
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*output_int(char **str, char *result, int i)
{
	if (str[0][i - 1] == '\n')
		return (result);
	else if (str[0][i - 1] == '\0')
	{
		free(*str);
		*str = 0;
		return (result);
	}
	else
	{
		free(*str);
		*str = 0;
		return (NULL);
	}
}

static int	where_is_n(char *str, int *i)
{
	int	j;

	j = *i;
	while (str[j] != '\0')
	{
		if (str[j] == '\n')
		{
			*i = j;
			return (j);
		}
		j++;
		if (str[j] == '\0')
		{
			*i = j;
			return (j);
		}
	}
	return (0);
}

static int	reader(char **str, int fd, int i)
{
	char		*temp;
	char		*temporary;
	int			read_count;

	temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (temp == 0)
		return (-1);
	read_count = read(fd, temp, BUFFER_SIZE);
	while (read_count > 0)
	{
		temp[read_count] = '\0';
		if (*str == 0)
			*str = ft_strdup(temp);
		else
		{
			temporary = ft_strjoin(*str, temp);
			free(*str);
			*str = temporary;
		}
		if (!str || ft_strchr(&((*str)[i]), '\n'))
			break ;
		read_count = read(fd, temp, BUFFER_SIZE);
	}
	free(temp);
	return (read_count);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;
	static int	i = 0;
	static int	j = 0;
	int			read_count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_count = reader(&str, fd, i);
	if (read_count == 0 && str == NULL)
		return (NULL);
	if (read_count < 0 || !str)
		return (NULL);
	where_is_n(str, &i);
	i += 1;
	result = ft_substr(str, j, (i - j));
	if (!result || *result == 0)
	{
		free(result);
		if (str != 0)
			free(str);
		return (NULL);
	}
	j = i;
	return (output_int(&str, result, i));
}
