/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deneme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:50:11 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/18 17:05:31 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(char *map, t_data *ptr, t_img *img)
{
	int		fd;
	char	*mapo;
	char	*line;

	img->sheight = 0;
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
	img->swidth = ft_strlen(line) - 1;
	while (line)
	{
		line = get_next_line(fd);
		img->sheight = img->sheight + 1;
	}
	close (fd);
	return (1);
}

int	photo_init(t_data	*ptr, t_img *p)
{
	int	x;
	int	y;

	p->wall = mlx_xpm_file_to_image(ptr->mlx_ptr, "./Assets/wall.xpm", &p->width, &p->height);
	p->player = mlx_xpm_file_to_image(ptr->mlx_ptr
	, "./Assets/player.xpm", &x, &y);
	p->collectible = mlx_xpm_file_to_image(ptr->mlx_ptr, "./Assets/collectible.xpm", &x, &y);
	p->space = mlx_xpm_file_to_image(ptr->mlx_ptr, "./Assets/empty.xpm", &x, &y);
	p->exit = mlx_xpm_file_to_image(ptr->mlx_ptr, "./Assets/exit.xpm", &x, &y);
	return (1);
}

int	main(int ac, char *av[])
{
	t_data	s_data;
	t_data	*ptr;
	t_img	*img;
	int		fd;

	ptr = &s_data;
	if (ac != 2)
		ft_printf("Invalid argument number !!!\n");
	img = malloc(sizeof(t_img));
	s_data.mlx_ptr = mlx_init();
	photo_init(ptr, img);
	read_map(av[1], ptr, img);
	s_data.win_ptr = mlx_new_window(s_data.mlx_ptr, (img->swidth * img->width), (img->sheight * img->height), "so_long");
	get_line(s_data, img);
	ft_printf("%s\n", s_data.map[2]);
	mlx_hook(s_data.win_ptr, 17, 0, shutdown, &s_data);
	mlx_hook(s_data.win_ptr, 2, 1L << 0, keyboard, &s_data);
	mlx_loop(s_data.mlx_ptr);
}
