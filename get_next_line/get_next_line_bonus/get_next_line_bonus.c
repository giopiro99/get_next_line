/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:21:43 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:33:43 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Reads from a file descriptor until a newline or EOF is reached.
 *
 * Reads BUFFER_SIZE bytes repeatedly from the given file descriptor `fd`
 * and concatenates the read data to `*result`. Stops reading if an error
 * occurs, end-of-file is reached, or a newline character is found.
 *
 * @param fd The file descriptor to read from.
 * @param result Pointer to a string pointer where the read data is accumulated.
 * @param buffer Temporary buffer for reading data.
 * @return char* Pointer to the accumulated string on success, NULL on error.
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
 * @brief Extracts the remainder of a line after the newline character.
 *
 * Searches for the newline character in the given string `line` and returns
 * a new string containing the part after the newline. The original `line`
 * is truncated to keep only up to the newline.
 *
 * @param line The string containing a line with a newline character.
 * @return char* The remainder of the line after the newline, or NULL if none.
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
 * Reads from the file descriptor `fd` and returns the next line, including
 * the terminating newline character if present. Supports multiple file
 * descriptors using a static array `rest` to store leftovers from previous calls.
 *
 * @param fd The file descriptor to read from.
 * @return char* The next line read from the file descriptor, or NULL on error or EOF.
 */
char	*get_next_line(int fd)
{
	static char	*rest[1024];
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
	line = ft_putline(fd, &rest[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	rest[fd] = ft_getrest(line);
	return (line);
}
/* int main()
{
	char	*line;
	int	fd[4];
	int	i = 0;

	fd[0] = open("text.txt", O_RDONLY);
	fd[1] = open("text1.txt", O_RDONLY);
	fd[2] = open("text2.txt", O_RDONLY);
	fd[3] = open("text3.txt", O_RDONLY);
	while (i < 4)
	{
		while((line = get_next_line(fd[i])) != NULL)
		{
			if(!line)
				return(1);
			printf("%s", line);
			free(line);
		}
		i++;
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
} */
/* int	main(void)
{
	char	*line;
	int	fd[4];

	fd[0] = open("text.txt", O_RDONLY);
	fd[1] = open("text1.txt", O_RDONLY);
	fd[2] = open("text2.txt", O_RDONLY);
	fd[3] = open("text3.txt", O_RDONLY);
	line = get_next_line(fd[0]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[1]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[2]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[3]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[0]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[1]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[2]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[3]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[0]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[1]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[2]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[3]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[0]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[1]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[2]);
	printf("%s", line);
	free(line);
	line = get_next_line(fd[3]);
	printf("%s", line);
	free(line);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
} */
