/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:08:16 by mkarabog          #+#    #+#             */
/*   Updated: 2023/06/22 19:02:02 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlenxx(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	frame(t_data *s_data)
{
	int		i;
	int		j;

	j = 0;
	while (i <= s_data->swidth - 1)
	{
		if (s_data->map[j][i] != '1' ||
		s_data->map[s_data->sheight - 1][i] != '1')
		{
			ft_printf("Map must be surrounded with walls !\n");
			exit (0);
		}
		i++;
	}
	i = 0;
	while (j <= s_data->sheight - 1)
	{
		if (s_data->map[j][i] != '1' ||
		s_data->map[j][s_data->swidth - 1] != '1')
		{
			ft_printf("Map must be surrounded with walls !\n");
			exit (0);
		}
		j++;
	}
}

int	quantity(t_data *s_data)
{
	if (s_data->p_quantity != 1)
	{
		ft_printf("Number of players must be 1\n");
		exit (0);
	}
	else if (s_data->e_quantity != 1)
	{
		ft_printf("Number of exit must be 1\n");
		exit (0);
	}
	else if (s_data->c_quantity <= 0)
	{
		ft_printf("There are at least one collectible exist in the map\n");
		exit (0);
	}
	frame(s_data);
	return (0);
}

void	peconezero(t_data *s_data)
{
	int		i;
	int		j;

	j = 0;
	while (s_data->map[j])
	{	
		i = 0;
		while (s_data->map[j][i] != '\0' && s_data->map[j][i] != '\n')
		{
			if (s_data->map[j][i] != 'P' && s_data->map[j][i] != 'E')
			{
				if (s_data->map[j][i] != 'C' && s_data->map[j][i] != '0')
				{
					if (s_data->map[j][i] != '1')
					{
						ft_printf("Map must be created using only 10PEC\n");
						exit (0);
					}
				}
			}
			i++;
		}
		j++;
	}
	quantity(s_data);
}

int	rectangular(t_data *s_data)
{
	int		i;
	int		len;
	char	*a;

	i = 0;
	len = ft_strlenxx(s_data->map[i]);
	while (s_data->map[i])
	{
		if (len != ft_strlenxx(s_data->map[i]))
		{
			ft_printf("Map must be rectangular !\n");
			exit (0);
		}
		i++;
	}
	peconezero(s_data);
	return (1);
}
