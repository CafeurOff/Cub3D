/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_check_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:50:33 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/29 21:54:21 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	ft_check_side(char **map, int j)
{
	int	i;

	i = 0;
	while (map[j][i])
	{
		if (!ft_isspace(map[j][i]))
			if (map[j][i] != '1')
				return (false);
		i++;
	}
	return (true);
}

bool	ft_check_middle(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			j++;
		if (map[i][j] != '1')
			return (false);
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_border(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_isspace(map[i][j]))
			{
				if (i > 0 && !ft_is_close(map[i - 1][j]))
					return (false);
				if (map[i + 1] && !ft_is_close(map[i + 1][j]))
					return (false);
				if (j > 0 && !ft_is_close(map[i][j - 1]))
					return (false);
				if (!ft_is_close(map[i][j + 1]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
bool	ft_check_current(char **map)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (map[i])
	{
		if (map[i + 1] && ft_strlen(map[i]) > ft_strlen(map[i + 1]))
		{
			tmp = ft_strlen(map[i]) - ft_strlen(map[i + 1]);
			tmp = ft_strlen(map[i]) - tmp;
			while (map[i][tmp])
			{
				if (map[i][tmp] != '1')
					return (false);
				tmp++;
			}
		}
		i++;
	}
	return (true);
}

bool	ft_check_next(char **map)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (map[i])
	{
		if (map[i + 1] && ft_strlen(map[i]) < ft_strlen(map[i + 1]))
		{
			tmp = ft_strlen(map[i + 1]) - ft_strlen(map[i]);
			tmp = ft_strlen(map[i + 1]) - tmp;
			while (map[i + 1][tmp])
			{
				if (map[i + 1][tmp] != '1')
					return (false);
				tmp++;
			}
		}
		i++;
	}
	return (true);
}
