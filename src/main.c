/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:33:33 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/29 22:19:10 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	int		check;
	t_map	*map;

	if (ac != 2)
		return (printf("Error\n Too few arguments"), 1);
	check = ft_check_extension(av[1]);
	if (check == 0)
		return (printf("Error\n"), 1);
	while (1)
	{
		map = ft_init_struct(av[1]);
		if (map->error > 0)
			return (1);
		game_init(map);
		if (map->error > 0)
			return (ft_terminate_struct(map), 1);
		if (map->game->game_over != 3)
		{
			ft_terminate_struct(map);
			break ;
		}
		ft_terminate_struct(map);
	}
	return (0);
}
