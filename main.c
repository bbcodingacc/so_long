/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:50:11 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/29 20:05:13 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(char *map, t_data *s_data)
{
	int		fd;
	char	*mapo;
	char	*line;

	s_data->sheight = 0;
	if (ft_strnstr(map + (ft_strlen(map - 4)), ".ber", 5) == NULL)
	{
		ft_printf("Map file is invalid (it must be in .ber format)");
		exit (0);
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error while reading .ber file");
		exit (0);
	}
	line = get_next_line(fd);
	s_data->swidth = ft_strlen(line) - 1;
	while (line)
	{
		line = get_next_line(fd);
		s_data->sheight = s_data->sheight + 1;
	}
	close (fd);
	return (1);
}

int	photo_init(t_data	*p)
{
	int	x;
	int	y;

	p->wall = mlx_xpm_file_to_image(p->mlx_ptr,
			"./Assets/wall.xpm", &p->width, &p->height);
	p->player = mlx_xpm_file_to_image(p->mlx_ptr,
			"./Assets/player.xpm", &x, &y);
	p->collec = mlx_xpm_file_to_image(p->mlx_ptr,
			"./Assets/collectible.xpm", &x, &y);
	p->space = mlx_xpm_file_to_image(p->mlx_ptr,
			"./Assets/empty.xpm", &x, &y);
	p->exit = mlx_xpm_file_to_image(p->mlx_ptr,
			"./Assets/exit.xpm", &x, &y);
	return (1);
}

int	main(int ac, char *av[])
{
	t_data	s_data;
	t_data	*ptr;

	ptr = &s_data;
	if (ac != 2)
		ft_printf("Invalid argument number !!!\n");
	s_data.mlx_ptr = mlx_init();
	photo_init(ptr);
	read_map(av[1], ptr);
	s_data.filename = av[1];
	s_data.win_ptr = mlx_new_window(s_data.mlx_ptr, (ptr->swidth * ptr->width), (ptr->sheight * ptr->height), "so_long");
	get_line(&s_data);
	control_all(&s_data);
	mlx_hook(s_data.win_ptr, 17, 0, shutdown, &s_data);
	mlx_hook(s_data.win_ptr, 2, 1L << 0, action, &s_data);
	mlx_loop(s_data.mlx_ptr);
}
