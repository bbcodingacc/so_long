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