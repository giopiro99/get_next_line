/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:21:43 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/01/08 14:42:35 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
