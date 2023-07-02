/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:56:10 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/30 23:43:53 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void destroy_mlx(t_data *s_data)
{
    mlx_destroy_window(s_data->mlx_ptr, s_data->win_ptr);
    mlx_destroy_image(s_data->mlx_ptr, s_data->collec);
    mlx_destroy_image(s_data->mlx_ptr, s_data->player);
    mlx_destroy_image(s_data->mlx_ptr, s_data->wall);
    mlx_destroy_image(s_data->mlx_ptr, s_data->exit);
    mlx_destroy_image(s_data->mlx_ptr, s_data->space);
}


void    free_array_main(t_data *s_data)
{
    int     i;

    i = 0;
    while (s_data->map[i])
    {
        free(s_data->map[i]);
        i++;
    }
    free(s_data->map);
}

void    free_array_tmp(t_data *s_data)
{
    int     i;

    i = 0;
    while (s_data->tmp_map[i])
    {
        free(s_data->tmp_map[i]);
        i++;
    }
    free(s_data->tmp_map);
}

int  free_array(t_data *s_data, int control)
{
    if(control == 0)
        free_array_main(s_data);
    else if(control == 2)
        free_array_tmp(s_data);
    else if(control == 3)
        destroy_mlx(s_data);
    else if(control == 4)
    {
        free_array_main(s_data);
        free_array_tmp(s_data);
        destroy_mlx(s_data);
    }
    return (0);
}

int ft_exit(t_data *s_data)
{
    free_array_main(s_data);
    destroy_mlx(s_data);
    exit (0);
}