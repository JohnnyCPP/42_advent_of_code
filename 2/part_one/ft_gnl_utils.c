/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:17:10 by jonnavar          #+#    #+#             */
/*   Updated: 2024/08/01 01:17:21 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_gnl_contains(const char *string, char character)
{
	char	*aux_pointer;
	int		index;

	if (!string)
		return (NULL);
	aux_pointer = (char *) string;
	index = 0;
	while (aux_pointer[index])
	{
		if (aux_pointer[index] == character)
			return (aux_pointer + index);
		index ++;
	}
	return (NULL);
}

size_t	ft_gnl_length(const char *string)
{
	size_t	index;

	if (!string)
		return (0);
	index = 0;
	while (string[index])
		index ++;
	return (index);
}

char	*ft_gnl_concat(const char *destination, const char *source)
{
	char		*result;
	size_t		result_length;
	ssize_t		source_length;
	ssize_t		dest_length;

	if (!destination || !source)
		return (NULL);
	result_length = ft_gnl_length(destination) + ft_gnl_length(source) + 1;
	result = (char *) malloc(sizeof(char) * result_length);
	if (!result)
		return (NULL);
	dest_length = -1;
	while (destination[++ dest_length])
		result[dest_length] = destination[dest_length];
	source_length = -1;
	while (source[++ source_length])
		result[dest_length + source_length] = source[source_length];
	result[dest_length + source_length] = '\0';
	return (result);
}

char	*ft_gnl_copy(const char *string)
{
	char	*result;
	ssize_t	index;
	ssize_t	result_length;

	if (!string)
		return (NULL);
	result_length = ft_gnl_length(string) + 1;
	result = (char *) malloc(sizeof(char) * result_length);
	if (!result)
		return (NULL);
	index = -1;
	while (++ index < result_length)
		result[index] = string[index];
	return (result);
}

char	*ft_gnl_cut(const char *string, size_t start, size_t length)
{
	char	*result;
	size_t	index;
	size_t	string_length;

	if (!string)
		return (NULL);
	string_length = ft_gnl_length(string);
	if (start > string_length)
		return (ft_gnl_copy(""));
	if (start + length > string_length)
		length = string_length - start;
	result = (char *) malloc(sizeof(char) * length + 1);
	if (!result)
		return (NULL);
	index = 0;
	while (string[start + index] && index < length)
	{
		result[index] = string[start + index];
		index ++;
	}
	result[index] = '\0';
	return (result);
}
