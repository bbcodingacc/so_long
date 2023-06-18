/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 03:02:37 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/18 20:34:18 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_mapxx(char **map)					/////////!!!!!!!!!!!!
{
	int	i = 0;
	int	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			ft_printf("%c", map[j][i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
	return (0);
}											//!!!!!!!!!!!!!!!!

int	count_object(char c, t_data *s_data, int i, int j)
{
	if (c == 'C')
		s_data->c_quantity = s_data->c_quantity + 1;
	else if (c == 'P')
	{
		s_data->player_x = i;
		s_data->player_y = j;
		s_data->p_quantity = s_data->p_quantity + 1;
	}
	//ft_printf("p quantitiy = %d\n", s_data->p_quantity);
	//ft_printf("c quantitiy = %d\n", s_data->c_quantity);
	return (0);
}

void	print_wall(t_data *s_data, int control)
{
	static int	i = 0;
	static int	j = 0;
	void		*mlx;
	void		*win;

	mlx = s_data->mlx_ptr;
	win = s_data->win_ptr;
	if (control == 'P')
		mlx_put_image_to_window(mlx, win, s_data->player, i, j);
	else if (control == '1')
		mlx_put_image_to_window(mlx, win, s_data->wall, i, j);
	else if (control == 'C')
		mlx_put_image_to_window(mlx, win, s_data->collectible, i, j);
	else if (control == '0')
		mlx_put_image_to_window(mlx, win, s_data->space, i, j);
	else if (control == 'E')
		mlx_put_image_to_window(mlx, win, s_data->exit, i, j);
	i = s_data->width + i;
	if (control == -1)
	{
		i = 0;
		j = s_data->width + j;
	}
	if (control == -2)
	{
		i = 0;
		j = 0;
	}
}

int	print_map(char c, t_data *s_data)
{
	if (c == '0')
		print_wall(s_data, '0');
	else if (c == '1')
		print_wall(s_data, '1');
	else if (c == 'C')
		print_wall(s_data, 'C');
	else if (c == 'E')
		print_wall(s_data, 'E');
	else if (c == 'P')
		print_wall(s_data, 'P');
	return (1);
}

int	read_line(char *str, t_data *s_data, int j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		print_map(str[i], s_data);
		count_object(str[i], s_data, i, j);
		i++;
	}
	print_wall(s_data, -1);
	return (1);
}

int	get_line_array(t_data *s_data)
{
	int		i;

	i = 0;
	s_data->c_quantity = 0;
	s_data->p_quantity = 0;
	print_wall(s_data, -2);
	while (s_data->map[i])
	{
		read_line(s_data->map[i], s_data, i);
		i++;
	}
	return (1);
}

int	get_line(t_data *s_data)
{
	int		fd;
	int		i;
	int		j;

	i = 0;
	s_data->c_quantity = 0;
	s_data->p_quantity = 0;
	fd = open(s_data->filename, O_RDONLY);
	while (1)
	{
		s_data->map[i] = get_next_line(fd);
		if (s_data->map[i] == NULL)
			break ;
		read_line(s_data->map[i], s_data, i);
		i++;
	}
	return (1);
}
