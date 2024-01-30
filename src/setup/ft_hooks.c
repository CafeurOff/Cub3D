/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:57:25 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/30 00:29:21 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_hooks(void *key)
{
	int		diff;
	t_game	*game;

	diff = 0;
	game = key;
	ft_on_exit(game);
	if (game->game_over == 0)
	{
		ft_move_left(game, diff);
		ft_move_right(game, diff);
		ft_mouvement(game);
		ft_raycaster(game);
	}
}

void	ft_on_exit(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (game->game_over == 2 && mlx_is_key_down(game->mlx, MLX_KEY_R))
	{
		game->game_over = 3;
		mlx_close_window(game->mlx);
	}
}
