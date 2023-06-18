/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:25:36 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/18 17:02:06 by mkarabog         ###   ########.fr       */
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
	char	*map[];
}t_data;

typedef struct	s_img
{
	void	*space;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
	int		width;
	int		height;
	int		swidth;
	int		sheight;
}t_img;


int		get_line(t_data s_data, struct s_img *img);
int		shutdown(t_data *s_data);
int		keyboard(int keycode, t_data *s_data);

#endif 