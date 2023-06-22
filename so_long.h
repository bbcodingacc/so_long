/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:25:36 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/22 19:14:34 by mkarabog         ###   ########.fr       */
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
	int		tmp_c_quantity;
	int		valid_e;


	void	*space;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
	int		width;
	int		height;
	int		swidth;
	int		sheight;

	char	**tmp_map;
	char	*map[];

	
}t_data;

int		get_line(t_data *s_data);
int		shutdown(t_data *s_data);
int		keyboard(int keycode, t_data *s_data);
int 	get_line_array(t_data *s_data);
int		action(int keycode, t_data *s_data);
int		rectangular(t_data *s_data);
void	path_check(t_data *data);
int		print_mapxx(char **map);	/////!!!!!!!!!!!!	
int		count_object(char c, t_data *s_data, int i, int j);

#endif 