#include "so_long.h"

int	print_mapxx(char **map)
{
	int	i = 0;
	int	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			ft_printf("%c", map[j][i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
	return (0);
}