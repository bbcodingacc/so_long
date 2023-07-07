/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:13:50 by mkarabog          #+#    #+#             */
/*   Updated: 2023/07/07 06:10:36 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	malloc_map(t_data *s_data)
{
	int		i;
	int		len;
	int		fd;
	char	*str;

	i = 0;
	fd = open(s_data->filename, O_RDONLY);
	if (fd == -1)
		return (0);
	s_data->map = (char **)malloc((s_data->sheight + 1) * sizeof(char *));
	if (s_data->map == NULL)
		return (1);
	while (i < s_data->sheight)
	{
		str = get_next_line(fd);
		len = ft_strlen(str);
		s_data->map[i] = (char *)malloc(len * sizeof(char));
		free(str);
		if (s_data->map[i] == NULL)
			return (1);
		i++;
	}
	s_data->map[i] = NULL;
	close (fd);
	return (0);
}

void	objects_to_zero(t_data *s_data, int x)
{
	s_data->c_quantity = 0;
	s_data->p_quantity = 0;
	s_data->e_quantity = 0;
	if (x == 1)
		s_data->movement = 0;
}

int	count_object(char c, t_data *s_data, int i, int j)
{
	if (c == 'C')
		s_data->c_quantity = s_data->c_quantity + 1;
	else if (c == 'E')
		s_data->e_quantity = s_data->e_quantity + 1;
	else if (c == 'P')
	{
		s_data->player_x = i;
		s_data->player_y = j;
		s_data->p_quantity = s_data->p_quantity + 1;
	}
	return (0);
}

int	last_new_line(t_data *s_data)
{
	int		y;
	int		x;

	y = s_data->sheight - 1;
	x = s_data->swidth;
	if (s_data->map[y][x] == '\n')
	{
		ft_printf("Last line cant be empty\n");
		return (1);
	}
	return (0);
}

size_t	ft_strlenxx(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}
