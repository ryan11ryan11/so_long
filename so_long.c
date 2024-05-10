/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:08:50 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/08 20:17:23 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_handling(t_map *map)
{
	if (map_component(map) == -1)
	{
		ft_printf("Number of C,E,P is not 1 or contains invalid characters in the map");
		return (-1);
	}
	if (is_rectengular(map) == -1)
	{
		ft_printf("Map is not rectengular");
		return (-1);
	}
	if (wall_checker(map) == -1)
	{
		ft_printf("Map is not covered by the wall");
		return (-1);
	}
	return (0);
}

int main()
{
	t_map map;

	int fd9 = open("yosi.ber", O_RDONLY);
	if (fd9 == -1)
	{
		printf("can not read the file");
		return (0);
	}
	map_initiate(&map);
	map_raw_data_maker(&map,fd9);
	map_parser(&map);
	if (error_handling(&map) == -1)
		return (0);
	printf("num_e:%d num_c:%d num_p:%d not_allowed:%d height:%d width_len:%d\n",map.num_e,map.num_c,map.num_p,map.not_allowed_char,map.height,map.width_len);
	free(map.map_raw_data);
	close(fd9);
}
