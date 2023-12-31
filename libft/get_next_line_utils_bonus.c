/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:05:46 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/06 21:35:56 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlenx(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	j;

	j = 0;
	if (!s)
		return (NULL);
	while (s[j] != (char)c)
	{
		if (s[j] == '\0')
			return (NULL);
		j++;
	}
	return (&((char *)s)[j]);
}

char	*add(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (s1);
	str = (char *)malloc((ft_strlenx(s1) + ft_strlenx(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*line(char *str)
{
	char	*r;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	r = (char *)malloc(i + 2);
	if (!r)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		r[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		r[i] = str[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	*next(char *s)
{
	char	*new;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	new = (char *)malloc((ft_strlenx(s) - i) + 1);
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		new[j++] = s[i++];
	new[j] = '\0';
	free(s);
	return (new);
}
