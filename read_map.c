/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 03:02:37 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/17 00:09:57 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		print_mapxx(char **map)
{
	int i = 0;
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
}
void	print_wall(t_data s_data, t_img *img, int control)
{
	static int	i = 0;
	static int	j = 0;
	void		*mlx;
	void		*win;

	mlx = s_data.mlx_ptr;
	win = s_data.win_ptr;
	if (control == 'P')
		mlx_put_image_to_window(mlx, win, img->player, i, j);
	else if (control == '1')
		mlx_put_image_to_window(mlx, win, img->wall, i, j);
	else if (control == 'C')
		mlx_put_image_to_window(mlx, win, img->collectible, i, j);
	else if (control == '0')
		mlx_put_image_to_window(mlx, win, img->space, i, j);
	else if (control == 'E')
		mlx_put_image_to_window(mlx, win, img->exit, i, j);
	i = img->width + i;
	if (control == -1)
	{
		i = 0;
		j = img->width + j;
	}
}

int	print_map(char c, t_data s_data, t_img *img)
{
	if (c == '0')
		print_wall(s_data, img, '0');
	else if (c == '1')
		print_wall(s_data, img, '1');
	else if (c == 'C')
		print_wall(s_data, img, 'C');
	else if (c == 'E')
		print_wall(s_data, img, 'E');
	else if (c == 'P')
		print_wall(s_data, img, 'P');
	return (1);
}

int	count_object(char c, t_data s_data, int	i, int j)
{
	ft_printf("func control\n");
	if(c == '0')
		s_data.c_quantity++;
	else if(c == 'P')
	{
		s_data.player_x = i;
		s_data.player_y = j;
	}
	ft_printf("player_x = %d\n", s_data.player_x);
	ft_printf("player_y = %d\n", s_data.player_y);
	return (0);
}

int	read_line(char *str, t_data s_data, t_img *img)
{
	int	i;

	i = 0;
	ft_printf("func check\n");
	while (str[i])
	{
		print_map(str[i], s_data, img);
		//count_object(str[i], s_data, i, j);
		i++;
	}
	print_wall(s_data, img, -1);
	return (1);
}

int	get_line(t_data s_data, t_img *img)
{
	int		fd;
	int		i;
	char	*line;
	
	i = 0;
	ft_printf("%s\n", s_data.filename);
	fd = open(s_data.filename, O_RDONLY);
	while (1)
	{
		s_data.map[i] = get_next_line(fd);
		if (s_data.map[i] == NULL)
			break ;
		read_line(s_data.map[i], s_data, img);
		i++;
	}
	return (1);
}

