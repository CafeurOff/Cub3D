/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_line_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:36:43 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/30 00:00:14 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_trim_space(char *line)
{
	char	*trim;
	int		i;
	int		j;
	int		count;

	i = -1;
	j = 0;
	count = 0;
	while (line[++i])
		if (ft_isspace(line[i]) == false)
			count++;
	trim = ft_calloc(count + 1, sizeof(char));
	if (!trim)
		return (NULL);
	i = -1;
	while (line[++i])
	{
		if (ft_isspace(line[i]) == false)
			trim[j++] = line[i];
	}
	return (trim);
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
