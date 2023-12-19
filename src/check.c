/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:32:02 by lduthill          #+#    #+#             */
/*   Updated: 2023/12/19 03:12:30 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_args(int ac, char **av)
{
	int		fd;
	char	*str;

	if (ac < 2 || ac > 3)
	{
		printf("Error\nWrong number of arguments\n");
		return (0);
	}
	if (ac == 3)
	{
		str = av[2];
		if (str[0] != '-' || str[1] != '-' || str[2] != 's' || str[3] != 'a'
			|| str[4] != 'v' || str[5] != 'e' || str[6] != '\0')
		{
			printf("Error\nWrong argument\n");
			return (0);
		}
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCan't open file\n");
		return (0);
	}
	return (1);
}

int	check_if_cube(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c'
		|| str[i - 4] != '.')
	{
		printf("Error\nWrong file extension\n");
		return (0);
	}
	return (1);
}

int	check_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != '2' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
		{
			printf("Error\nWrong map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map2(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			j++;
		i++;
	}
	if (j != 1)
	{
		printf("Error\nWrong map\n");
		return (0);
	}
	return (1);
}
