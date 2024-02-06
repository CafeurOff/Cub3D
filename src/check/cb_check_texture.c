/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_check_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:32:33 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/29 23:57:29 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_get_texture(t_map *map, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			return(printf("Error\nTab is not allowed..\n"), 1);
		i++;
	}
	i = 0;
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	while (line[i + j])
		j++;
	if (ft_strncmp(line, "NO ", 3) == 0 && !map->no)
		map->no = ft_substr(line, i, j - 1);
	else if (ft_strncmp(line, "SO ", 3) == 0 && !map->so)
		map->so = ft_substr(line, i, j - 1);
	else if (ft_strncmp(line, "WE ", 3) == 0 && !map->we)
		map->we = ft_substr(line, i, j - 1);
	else if (ft_strncmp(line, "EA ", 3) == 0 && !map->ea)
		map->ea = ft_substr(line, i, j - 1);
	else
		return (printf("Error\nDuplicate NO,SE,WE or EA\n"), 1);
	return (0);
}
