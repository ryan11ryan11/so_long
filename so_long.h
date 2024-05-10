/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:11:14 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/08 20:06:00 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char	*map_raw_data;
	int	num_e;
	int	num_c;
	int	num_p;
	int	width_len;
	int	height;
	int	not_allowed_char;
}   t_map;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);

int	map_raw_data_maker(t_map *map, int fd);
void	map_parser(t_map *map);
int	is_rectengular(t_map *map);
void	map_initiate(t_map *map);
int		ft_printf(const char *contentptr, ...);

int	map_component(t_map *map);
int	wall_checker(t_map *map);


#endif
