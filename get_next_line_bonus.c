/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:02:52 by kzerri            #+#    #+#             */
/*   Updated: 2022/11/17 22:44:24 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join_free(char *buffer, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buff);
	free(buffer);
	return (tmp);
}

char	*next_line(char *buffer)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*buffer)
		return (free(buffer), NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	buff = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
	if (!buff)
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		buff[j++] = buffer[i++];
	return (free(buffer), buff[j] = 0, buff);
}

char	*get_my_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!*buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line[i] = '\0', line);
}

char	*read_file(int fd, char *buffer)
{
	char	*buff;
	int		n_bytes;

	if (!buffer)
		buffer = ft_strdup("");
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		free(buffer);
		return (NULL);
	}
	n_bytes = 1;
	while (!(ft_strchr(buffer, '\n')) && n_bytes != 0)
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == -1)
			return (free(buff), free(buffer), NULL);
		buff[n_bytes] = '\0';
		buffer = ft_join_free(buffer, buff);
	}
	return (free(buff), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(buffer[fd]), buffer[fd] = NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_my_line(buffer[fd]);
	buffer[fd] = next_line(buffer[fd]);
	return (line);
}
