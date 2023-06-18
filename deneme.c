/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deneme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:50:11 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/18 20:36:23 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(char *map, t_data *ptr)
{
	int		fd;
	char	*mapo;
	char	*line;

	ptr->sheight = 0;
	mapo = ft_strnstr(map + (ft_strlen(map - 4)), ".ber", 5);
	if (mapo == NULL)
	{
		ft_printf("Map file is invalid (it must be in .ber format)");
		return (30);
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error while reading .ber file");
		return (31);
	}
	ptr->filename = map;
	line = get_next_line(fd);
	ptr->swidth = ft_strlen(line) - 1;
	while (line)
	{
		line = get_next_line(fd);
		ptr->sheight = ptr->sheight + 1;
	}
	close (fd);
	return (1);
}

int	photo_init(t_data	*ptr)
{
	int	x;
	int	y;

	ptr->wall = mlx_xpm_file_to_image(ptr->mlx_ptr, "./Assets/wall.xpm", &ptr->width, &ptr->height);
	ptr->player = mlx_xpm_file_to_image(ptr->mlx_ptr, "./Assets/player.xpm", &x, &y);
	ptr->collectible = mlx_xpm_file_to_image(ptr->mlx_ptr, "./Assets/collectible.xpm", &x, &y);
	ptr->space = mlx_xpm_file_to_image(ptr->mlx_ptr, "./Assets/empty.xpm", &x, &y);
	ptr->exit = mlx_xpm_file_to_image(ptr->mlx_ptr, "./Assets/exit.xpm", &x, &y);
	return (1);
}

int	main(int ac, char *av[])
{
	t_data	s_data;
	t_data	*ptr;
	int		fd;

	ptr = &s_data;
	if (ac != 2)
		ft_printf("Invalid argument number !!!\n");
	s_data.mlx_ptr = mlx_init();
	photo_init(ptr);
	read_map(av[1], ptr);
	s_data.win_ptr = mlx_new_window(s_data.mlx_ptr, (ptr->swidth * ptr->width), (ptr->sheight * ptr->height), "so_long");
	get_line(&s_data);
	mlx_hook(s_data.win_ptr, 17, 0, shutdown, &s_data);
	mlx_hook(s_data.win_ptr, 2, 1L << 0, action, &s_data);
	mlx_loop(s_data.mlx_ptr);
}
