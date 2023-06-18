/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:06:09 by ydegerli          #+#    #+#             */
/*   Updated: 2023/03/06 15:03:00 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*scan(int fd, char *s)
{
	char	*l;
	int		lw;

	l = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!l)
		return (NULL);
	lw = 1;
	while (lw != 0 && !ft_strchr(s, '\n'))
	{
		lw = read(fd, l, BUFFER_SIZE);
		if (lw == -1)
		{
			free(l);
			return (NULL);
		}
		l[lw] = 0;
		s = add(s, l);
		if (!s)
			return (NULL);
	}
	free(l);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*stc[256];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stc[fd] = scan(fd, stc[fd]);
	if (!stc[fd])
		return (NULL);
	str = line(stc[fd]);
	stc[fd] = next(stc[fd]);
	return (str);
}
