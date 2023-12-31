/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:27:22 by mkarabog          #+#    #+#             */
/*   Updated: 2023/07/07 13:03:19 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shutdown(t_data *s_data)
{
	ft_printf("X\n");
	ft_exit(s_data);
	return (0);
}

int	wall_control(t_data *s_data, int x, int y)
{
	if (s_data->map[y][x] == '1')
		return (1);
	else if (s_data->map[y][x] == 'E')
	{	
		if (s_data->c_quantity == 0)
		{
			s_data->movement++;
			return (2);
		}
		else
			return (1);
	}
	else
		return (0);
}

int	move_y(int keycode, t_data *s_data)
{
	int		x;
	int		y;
	int		swap;

	x = s_data->player_x;
	y = s_data->player_y;
	swap = y;
	if (keycode == 1)
		y = y + 1;
	else
		y = y - 1;
	if (wall_control(s_data, x, y) == 2)
	{
		ft_printf("Movement quantity = %d\n", s_data->movement);
		ft_exit(s_data);
	}
	if (wall_control(s_data, x, y) == 1)
		return (0);
	s_data->map[swap][x] = '0';
	s_data->map[y][x] = 'P';
	s_data->player_x = x;
	s_data->player_y = y;
	s_data->movement++;
	ft_printf("Movement quantity = %d\n", s_data->movement);
	return (1);
}

int	move_x(int keycode, t_data *s_data)
{
	int		x;
	int		y;
	int		swap;

	x = s_data->player_x;
	y = s_data->player_y;
	swap = x;
	if (keycode == 0)
		x = x - 1;
	else
		x = x + 1;
	if (wall_control(s_data, x, y) == 2)
	{
		ft_printf("Movement quantity = %d\n", s_data->movement);
		ft_exit(s_data);
	}
	if (wall_control(s_data, x, y) == 1)
		return (0);
	s_data->map[y][swap] = '0';
	s_data->map[y][x] = 'P';
	s_data->player_x = x;
	s_data->player_y = y;
	s_data->movement++;
	ft_printf("Movement quantity = %d\n", s_data->movement);
	return (1);
}

int	action(int keycode, t_data *s_data)
{
	if (keycode == 13 || keycode == 1)
		move_y(keycode, s_data);
	else if (keycode == 2 || keycode == 0)
		move_x(keycode, s_data);
	else if (keycode == 53)
		ft_exit(s_data);
	mlx_clear_window(s_data->mlx_ptr, s_data->win_ptr);
	get_line_array(s_data);
	return (0);
}
