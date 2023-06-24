/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:13:50 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/24 22:29:37 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		exit (0);
	}
	return (0);
}
