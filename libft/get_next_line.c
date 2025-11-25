/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:51:56 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/11/25 15:38:14 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_buff(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	str = malloc((ft_strlenn(buffer) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (buffer[i] && buffer[++i])
		str[j++] = buffer[i];
	str[j] = '\0';
	return (free(buffer), str);
}

char	*ft_fill_file(char *buffer)
{
	int		i;
	int		len;
	char	*line;

	len = 0;
	if (!buffer)
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (free(buffer), NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *buffer)
{
	int		byte;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(buffer), NULL);
	byte = 1;
	buff[0] = '\0';
	while (!ft_strchrr(buffer, '\n') && byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte < 0)
			return (free(buff), free(buffer), NULL);
		buff[byte] = '\0';
		buffer = ft_strjoinn(buffer, buff);
		if (!buffer)
			return (NULL);
	}
	if (ft_strlenn(buffer) == 0)
		return (free(buff), free(buffer), NULL);
	return (free(buff), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_fill_file(buffer);
	buffer = ft_fill_buff(buffer);
	if (!line)
		free(buffer);
	return (line);
}