/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:26:05 by slippert          #+#    #+#             */
/*   Updated: 2024/01/28 11:49:31 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next(char *res_buf)
{
	int		i;
	int		j;
	int		length;
	char	*rem_buf;

	i = 0;
	while (res_buf[i] && res_buf[i] != '\n')
		i++;
	if (!res_buf[i])
		return (free(res_buf), res_buf = NULL);
	length = 0;
	while (res_buf[length])
		length++;
	if (length - 1 < 1)
		return (free(res_buf), res_buf = NULL);
	rem_buf = ft_calloc(length - i + 1, sizeof(char));
	if (!rem_buf)
		return (free(res_buf), res_buf = NULL);
	i++;
	j = 0;
	while (res_buf[i])
		rem_buf[j++] = res_buf[i++];
	return (free(res_buf), res_buf = NULL, rem_buf);
}

char	*ft_line(char *res_buf)
{
	char	*line;
	int		i;
	int		extra_storage;

	if (!res_buf[0])
		return (NULL);
	i = 0;
	while (res_buf[i] && res_buf[i] != '\n')
		i++;
	extra_storage = 2;
	if (res_buf[i] != '\n')
		extra_storage = 1;
	line = ft_calloc(i + extra_storage, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (res_buf[i] && res_buf[i] != '\n')
	{
		line[i] = res_buf[i];
		i++;
	}
	if (res_buf[i] && res_buf[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_read_file(int fd, char *res_buf)
{
	char	*temp_buf;
	int		bytes;

	if (!res_buf)
		res_buf = ft_calloc(1, sizeof(char));
	if (!res_buf)
		return (NULL);
	temp_buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buf)
		return (free(res_buf), res_buf = NULL);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, temp_buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(temp_buf), NULL);
		temp_buf[bytes] = '\0';
		res_buf = ft_free(res_buf, temp_buf);
		if (!res_buf)
			return (res_buf = NULL);
		if (ft_strchr(res_buf, '\n'))
			break ;
	}
	return (free(temp_buf), res_buf);
}

char	*get_next_line(int fd)
{
	static char	*res_buf[FD_SETSIZE] = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (res_buf[fd])
		{
			free(res_buf[fd]);
			res_buf[fd] = NULL;
		}
		return (NULL);
	}
	res_buf[fd] = ft_read_file(fd, res_buf[fd]);
	if (!res_buf[fd])
		return (NULL);
	line = ft_line(res_buf[fd]);
	res_buf[fd] = ft_next(res_buf[fd]);
	if (!line)
		return (free(res_buf[fd]), res_buf[fd] = NULL, line = NULL);
	if (res_buf[fd] && ((line && line[0] == '\0') || res_buf[fd][0] == '\0'))
		return (free(res_buf[fd]), res_buf[fd] = NULL, line);
	return (line);
}
