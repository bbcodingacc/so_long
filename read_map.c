/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 03:02:37 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/30 23:47:07 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		malloc_map(t_data *s_data)
{
	int		i;
	int		len;
	int		fd;

	i = 0;
	fd = open(s_data->filename, O_RDONLY);
	if(fd == -1)
		return (0);
	s_data->map = (char **)malloc((s_data->sheight + 1) * sizeof(char *));
	if(s_data->map == NULL)
		return (1);
	while (i < s_data->sheight)
	{
		len = ft_strlen(get_next_line(fd));
		s_data->map[i] = (char *)malloc(len * sizeof(char));
		if(s_data->map[i] == NULL)
			return (1);
		i++;
	}
	s_data->map[i] = NULL;
	close (fd);
	return (0);
}

void	print_wall(t_data *s_data, int control)
{
	static int	i = 0;
	static int	j = 0;
	void		*win;

	win = s_data->win_ptr;
	if (control == 'P')
		mlx_put_image_to_window(s_data->mlx_ptr, win, s_data->player, i, j);
	else if (control == '1')
		mlx_put_image_to_window(s_data->mlx_ptr, win, s_data->wall, i, j);
	else if (control == 'C')
		mlx_put_image_to_window(s_data->mlx_ptr, win, s_data->collec, i, j);
	else if (control == '0')
		mlx_put_image_to_window(s_data->mlx_ptr, win, s_data->space, i, j);
	else if (control == 'E')
		mlx_put_image_to_window(s_data->mlx_ptr, win, s_data->exit, i, j);
	i = s_data->width + i;
	if (control == -1 || control == -2)
	{
		i = 0;
		if (control == -2)
			j = 0;
		else
			j = s_data->width + j;
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
	s_data->e_quantity = 0;
	print_wall(s_data, -2);
	print_mapxx(s_data->map);
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
	s_data->e_quantity = 0;
	s_data->movement = 0;
	malloc_map(s_data);
	fd = open(s_data->filename, O_RDONLY);
	if(fd == -1)
		return (ft_exit(s_data));
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
