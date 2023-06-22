/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:25:36 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/22 15:26:56 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>


typedef struct s_data // kaynak
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*filename;
	int		player_x;
	int		player_y;
	int 	c_quantity;
	int		p_quantity;
	int		e_quantity;


	void	*space;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
	int		width;
	int		height;
	int		swidth;
	int		sheight;

	char	*map[];

	
}t_data;

int		get_line(t_data *s_data);
int		shutdown(t_data *s_data);
int		keyboard(int keycode, t_data *s_data);
int 	get_line_array(t_data *s_data);
int		action(int keycode, t_data *s_data);
int		rectangular(t_data *s_data);

#endif 