/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:59:40 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/29 23:59:02 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_mouvement(t_game *game)
{
	ft_offset(game);
	ft_move_up(game);
	ft_straf(game);
}

void	ft_move_left(t_game *game, int diff)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->cast->pa -= 0.05;
		if (game->cast->pa < 0)
			game->cast->pa += 2 * M_PI;
	}
	else if (diff > 0)
	{
		if ((diff) > 150)
			diff = 150;
		game->cast->pa -= 0.0006 * diff;
		if (game->cast->pa < 0)
			game->cast->pa += 2 * M_PI;
	}
}

void	ft_move_right(t_game *game, int diff)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->cast->pa += 0.05;
		if (game->cast->pa > 2 * M_PI)
			game->cast->pa -= 2 * M_PI;
	}
	else if (diff < 0)
	{
		if ((-diff) > 150)
			diff = -150;
		game->cast->pa += 0.0006 * (-diff);
		if (game->cast->pa > 2 * M_PI)
			game->cast->pa -= 2 * M_PI;
	}
}

void	ft_move_up(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		ft_w_move(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		if (ft_check_collision(game->cast->map[(int)game->pl_y / 128]
				[(int)(game->pl_x - game->cast->x_off) / 128]))
			game->pl_x -= cos(game->cast->pa) * 6;
		if (ft_check_collision(game->cast->map
				[(int)(game->pl_y - game->cast->y_off) / 128]
			[(int)game->pl_x / 128]))
			game->pl_y -= sin(game->cast->pa) * 6;
	}
}

void	ft_w_move(t_game *game)
{
	if (ft_check_collision(game->cast->map[(int)game->pl_y / 128]
			[(int)(game->pl_x + game->cast->x_off) / 128]))
	{
		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
			game->pl_x += cos(game->cast->pa) * 10;
		else
			game->pl_x += cos(game->cast->pa) * 6;
	}
	if (ft_check_collision(game->cast->map
			[(int)(game->pl_y + game->cast->y_off) / 128]
		[(int)game->pl_x / 128]))
	{
		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
			game->pl_y += sin(game->cast->pa) * 10;
		else
			game->pl_y += sin(game->cast->pa) * 6;
	}
}
