/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:21:43 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:32:50 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Reads from a file descriptor until a newline or EOF is found,
 *        concatenating the read content into a dynamically allocated string.
 *
 * Reads BUFFER_SIZE bytes at a time into buffer, appending the content to
 * *result. Stops reading when a newline character is found or EOF is reached.
 *
 * @param fd The file descriptor to read from.
 * @param result Pointer to a string where the read data is accumulated.
 * @param buffer Temporary buffer for reading data.
 * @return char* The accumulated string including the newline if found, or NULL on error.
 */
static char	*ft_putline(int fd, char **result, char *buffer)
{
	ssize_t	bt_read;
	char	*tmp;

	while (1)
	{
		bt_read = read(fd, buffer, BUFFER_SIZE);
		if (bt_read == -1)
		{
			free(*result);
			*result = NULL;
			return (NULL);
		}
		else if (bt_read == 0)
			break ;
		buffer[bt_read] = '\0';
		if (!*result)
			*result = ft_strdup("");
		tmp = *result;
		*result = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (*result);
}

/**
 * @brief Extracts and returns the remaining part of the line after the first newline.
 *
 * Finds the newline character in the line, terminates the original string after it,
 * and returns a newly allocated string containing the rest of the content after
 * the newline. Returns NULL if there is no remaining content.
 *
 * @param line The line containing a newline character.
 * @return char* Newly allocated string of the content after the newline, or NULL if none.
 */
static char	*ft_getrest(char *line)
{
	ssize_t	i;
	char	*rest;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	rest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!rest)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (rest);
}

/**
 * @brief Reads the next line from a file descriptor.
 *
 * Uses a static variable to store leftover data between calls. Reads data until
 * a newline or EOF is found, then returns the line including the newline.
 *
 * @param fd The file descriptor to read from.
 * @return char* The next line read from fd, or NULL on error or EOF.
 */
char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_putline(fd, &rest, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	rest = ft_getrest(line);
	return (line);
}
/* int main()
{
	char	*line;
	int	fd;

	fd = open("text.txt", O_WRONLY);
	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			return(1);
		printf("%s", line);
		free(line);
	}
	close(fd);
} */
