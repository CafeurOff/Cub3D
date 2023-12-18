/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <lduthill@42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:40:57 by lduthill          #+#    #+#             */
/*   Updated: 2023/12/18 18:31:53 by lduthill         ###   ########.fr       */
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
	ft_check_args(ac, av);
	ft_init_mlx(data);
}
