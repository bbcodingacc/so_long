#include "so_long.h"

int shutdown(t_data *s_data)
{
    ft_printf("X\n");
    exit(0);
}

int keyboard(int keycode, t_data *s_data)
{
    if (keycode == 119 || keycode == 13)
               ft_printf("W\n");
        else if (keycode == 115 || keycode == 1)
                ft_printf("S\n");
        else if (keycode == 100 || keycode == 2)
                ft_printf("D\n");
        else if (keycode == 97 || keycode == 0)
                ft_printf("A\n");
        else if (keycode == 53 || keycode == 65307)
                ft_printf("ESC\n");
        return (0);
}

int wall_control(t_data *s_data, int x, int y)
{
	ft_printf("p quantitiy = %d\n", s_data->p_quantity);
	ft_printf("c quantitiy = %d\n", s_data->c_quantity);
	if(s_data->map[y][x] == '1')
		return (1);
	else
		return (0);
}

int move_y(int keycode, t_data *s_data)
{
	int		x;
	int		y;
	int		swap;

	x = s_data->player_x;
	y = s_data->player_y;
	swap = y;
	if(keycode == 1)
		y = y + 1;
	else
		y = y - 1;
	if(wall_control(s_data, x, y) == 1)
		return (0);
	s_data->map[swap][x] = '0';
	s_data->map[y][x] = 'P';
	s_data->player_x = x;
	s_data->player_y = y;
	return (1);
}

int move_x(int keycode, t_data *s_data)
{
	int		x;
	int		y;
	int		swap;

	x = s_data->player_x;
	y = s_data->player_y;
	swap = x;
	if(keycode == 0)
		x = x - 1;
	else
		x = x + 1;
	if(wall_control(s_data, x, y) == 1)
		return (0);
	s_data->map[y][swap] = '0';
	s_data->map[y][x] = 'P';
	s_data->player_x = x;
	s_data->player_y = y;
	return (1);
}

int action(int keycode, t_data *s_data)
{
	keyboard(keycode, s_data);
	if(keycode == 13 || keycode == 1)
		move_y(keycode, s_data);
	else if(keycode == 2 || keycode == 0)
		move_x(keycode, s_data);
	mlx_clear_window(s_data->mlx_ptr, s_data->win_ptr);
	get_line_array(s_data);
    return (0);
}