/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:46:53 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:35:32 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Allocates and returns a duplicate of the input string.
 *
 * Allocates sufficient memory for a copy of the string s, copies it,
 * and returns a pointer to the new string.
 *
 * @param s The string to duplicate.
 * @return char* Pointer to the newly allocated duplicated string, or NULL on failure.
 */
char	*ft_strdup(char *s)
{
	size_t	i;
	char	*str;

	i = ft_strlen(s);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * @brief Calculates the length of a null-terminated string.
 *
 * Iterates through the string until the null terminator is found,
 * returning the number of characters before it.
 *
 * @param s The input string.
 * @return size_t The length of the string.
 */
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * @brief Concatenates two strings into a newly allocated string.
 *
 * Allocates memory for a new string that contains s1 followed by s2,
 * and returns it. Returns NULL if allocation fails.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return char* The newly allocated concatenated string, or NULL on failure.
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (s1[j] != '\0')
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * @brief Creates a substring from the given string.
 *
 * Allocates and returns a new string which is a substring of s,
 * starting at index start and of maximum length len.
 * Returns NULL if start is beyond the end of s or on allocation failure.
 *
 * @param s The original string.
 * @param start The start index for the substring.
 * @param len The maximum length of the substring.
 * @return char* The newly allocated substring, or NULL.
 */
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * @brief Locates the first occurrence of character c in string s.
 *
 * Searches for the first occurrence of c in s, including the terminating
 * null byte. Returns a pointer to the matched character or NULL if not found.
 *
 * @param s The string to search.
 * @param c The character to find (as int).
 * @return char* Pointer to the first occurrence of c, or NULL if not found.
 */
char	*ft_strchr(char *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
