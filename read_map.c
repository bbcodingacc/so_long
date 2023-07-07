/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 03:02:37 by mkarabog          #+#    #+#             */
/*   Updated: 2023/07/07 05:57:53 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	objects_to_zero(s_data, 0);
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
	int		len;
	char	*str;

	i = 0;
	objects_to_zero(s_data, 1);
	malloc_map(s_data);
	fd = open(s_data->filename, O_RDONLY);
	if (fd == -1)
		return (ft_exit(s_data));
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		len = ft_strlen(str) + 1;
		ft_strlcat(s_data->map[i], str, len);
		if (s_data->map[i] == NULL)
			break ;
		free(str);
		read_line(s_data->map[i], s_data, i);
		i++;
	}
	return (1);
}
