/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:17:10 by jonnavar          #+#    #+#             */
/*   Updated: 2024/08/01 01:17:21 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	char	*ft_gnl_check_nl(int next_line, char **file_address)
{
	char	*substring;
	char	*result;

	substring = NULL;
	if (next_line <= 0)
	{
		if (**file_address == '\0')
		{
			free(*file_address);
			*file_address = NULL;
			return (NULL);
		}
		result = *file_address;
		*file_address = NULL;
		return (result);
	}
	substring = ft_gnl_cut(*file_address, next_line, BUFFER_SIZE);
	result = *file_address;
	result[next_line] = '\0';
	*file_address = substring;
	return (result);
}

static	void	ft_gnl_free_address(char **pointer)
{
	if (*pointer)
	{
		free(*pointer);
		pointer = NULL;
	}
}

static	char	*ft_gnl_read(int fd, char **file_address, char *reading_buffer)
{
	ssize_t	bytes_read;
	char	*saved_str;
	char	*next_line;

	bytes_read = 0;
	saved_str = NULL;
	next_line = ft_gnl_contains(*file_address, '\n');
	while (!next_line)
	{
		bytes_read = read(fd, reading_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (ft_gnl_check_nl(bytes_read, file_address));
		reading_buffer[bytes_read] = '\0';
		saved_str = ft_gnl_concat(*file_address, reading_buffer);
		ft_gnl_free_address(file_address);
		*file_address = saved_str;
		next_line = ft_gnl_contains(*file_address, '\n');
	}
	return (ft_gnl_check_nl(next_line - *file_address + 1, file_address));
}

char	*ft_gnl(int fd)
{
	static char	*file_addresses[LAST_FD + 1];
	char		*reading_buffer;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > LAST_FD)
		return (NULL);
	reading_buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!reading_buffer)
		return (NULL);
	if (!file_addresses[fd])
		file_addresses[fd] = ft_gnl_copy("");
	result = ft_gnl_read(fd, &file_addresses[fd], reading_buffer);
	ft_gnl_free_address(&reading_buffer);
	return (result);
}
