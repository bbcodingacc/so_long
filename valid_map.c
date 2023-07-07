/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:00:39 by mkarabog          #+#    #+#             */
/*   Updated: 2023/07/07 11:33:51 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**map_dup(t_data *s_data)
{
	int		i;
	int		j;

	j = 0;
	s_data->tmp_map = (char **)malloc(s_data->height * sizeof(char *));
	while (s_data->map[j])
	{
		i = 0;
		s_data->tmp_map[j] = (char *)malloc(s_data->swidth * sizeof(char));
		while (s_data->map[j][i])
		{
			s_data->tmp_map[j][i] = s_data->map[j][i];
			i++;
		}
		j++;
	}
	s_data->tmp_map[j] = NULL;
	return (NULL);
}

void	validmap_check(t_data *s_data, int x, int y)
{
	char	*p;

	p = &s_data->tmp_map[y][x];
	if (*p == 'E')
		s_data->valid_e = 1;
	if (*p != 'E' && *p != '1')
	{
		if (*p == 'C')
			s_data->tmp_c_quantity--;
		*p = '.';
		if (s_data->tmp_map[y][x + 1] != '1' &&
			s_data->tmp_map[y][x + 1] != '.')
			validmap_check(s_data, x + 1, y);
		if (s_data->tmp_map[y][x - 1] != '1' &&
			s_data->tmp_map[y][x - 1] != '.')
			validmap_check(s_data, x - 1, y);
		if (s_data->tmp_map[y - 1][x] != '1' &&
			s_data->tmp_map[y - 1][x] != '.')
			validmap_check(s_data, x, y - 1);
		if (s_data->tmp_map[y + 1][x] != '1' &&
			s_data->tmp_map[y + 1][x] != '.')
			validmap_check(s_data, x, y + 1);
	}
}

int	path_check(t_data *s_data)
{
	map_dup(s_data);
	s_data->tmp_c_quantity = s_data->c_quantity;
	s_data->valid_e = 0;
	validmap_check(s_data, s_data->player_x, s_data->player_y);
	if (s_data->valid_e == 0 || s_data->tmp_c_quantity > 0)
	{
		ft_printf("Path isn't valid\n");
		free_array(s_data, 2);
		return (1);
	}
	free_array(s_data, 2);
	return (0);
}
