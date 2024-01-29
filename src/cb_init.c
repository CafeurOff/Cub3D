/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:22:32 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/29 22:19:15 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map	*ft_init_struct(char *path)
{
	t_map		*map;

	map = malloc(sizeof(t_map));
	map->error = 0;
	map->fd = open(path, O_RDONLY);
	if (!map->fd)
		return (map->error = 2, map);
	ft_init_null(map);
	map->map = NULL;
	if (ft_get_map(map) == 1)
		return (map->error = 1, map);
	map->map = ft_setmap(map->fd);
	if (map->map == NULL)
		return (map->error = 1, map);
	ft_allocate_helper_structs(map);
	return (map);
}

void	ft_init_null(t_map *map)
{
	int	i;

	i = -1;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	while (++i < 3)
	{
		map->floor[i] = -1;
		map->ceiling[i] = -1;
	}
}
