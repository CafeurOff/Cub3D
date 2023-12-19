/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:40:57 by lduthill          #+#    #+#             */
/*   Updated: 2023/12/19 03:11:45 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_mlx(t_vars data)
{
	data.width = 64;
	data.height = 64;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width * 64,
			data.height * 64 + 20, "So Long !");
	mlx_loop(data.mlx);
}

int		main(int ac, char **av)
{
	t_vars data;

	(void)av;
	(void)ac;
	if (ft_check_args(ac, av) == 0)
		return (0);
	if (check_if_cube(av[1]) == 0)
		return (0);
	ft_init_mlx(data);
	return (0);
}
