/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:00:39 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/22 19:04:56 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_dup(t_data *s_data)
{
	int		i;
	int		j;
	int		x;
	char	**map;

	j = 0;
	map = (char **)malloc(s_data->height * sizeof(char *));
	while (s_data->map[j])
	{
		i = 0;
		map[j] = (char *)malloc(s_data->swidth * sizeof(char));
		while (s_data->map[j][i])
		{
			map[j][i] = s_data->map[j][i];
			i++;
		}
		j++;
	}
	return (map);
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

void	path_check(t_data *s_data)
{
	int		i;

	i = 0;
	s_data->tmp_map = map_dup(s_data);
	s_data->tmp_c_quantity = s_data->c_quantity;
	s_data->valid_e = 0;
	validmap_check(s_data, s_data->player_x, s_data->player_y);
	if (s_data->valid_e == 0 || s_data->tmp_c_quantity > 0)
	{
		ft_printf("Path isn't valid\n");
		exit (0);
	}
}
