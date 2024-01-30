/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:01:33 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/30 00:00:17 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_offset(t_game *game)
{
	game->cast->pd_x = cos(game->cast->pa) * 6;
	game->cast->pd_y = sin(game->cast->pa) * 6;
	if (game->cast->pd_x < 0)
		game->cast->x_off = -20;
	else
		game->cast->x_off = 20;
	if (game->cast->pd_y < 0)
		game->cast->y_off = -20;
	else
		game->cast->y_off = 20;
	game->cast->pd_x_strafe = cos(game->cast->pa + M_PI_2) * 6;
	game->cast->pd_y_strafe = sin(game->cast->pa + M_PI_2) * 6;
	if (game->cast->pd_x_strafe < 0)
		game->cast->x_off_strafe = -20;
	else
		game->cast->x_off_strafe = 20;
	if (game->cast->pd_y_strafe < 0)
		game->cast->y_off_strafe = -20;
	else
		game->cast->y_off_strafe = 20;
}

void	ft_straf(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		if (ft_check_collision(game->cast->map[(int)game->pl_y / 128]
				[(int)(game->pl_x + game->cast->x_off_strafe) / 128]))
			game->pl_x += cos(game->cast->pa + M_PI_2) * 6;
		if (ft_check_collision(game->cast->map
				[(int)(game->pl_y + game->cast->y_off_strafe) / 128]
			[(int)game->pl_x / 128]))
			game->pl_y += sin(game->cast->pa + M_PI_2) * 6;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		if (ft_check_collision(game->cast->map[(int)game->pl_y / 128]
				[(int)(game->pl_x - game->cast->x_off_strafe) / 128]))
			game->pl_x -= cos(game->cast->pa + M_PI_2) * 6;
		if (ft_check_collision(game->cast->map[(int)(game->pl_y
					- game->cast->y_off_strafe) / 128]
			[(int)game->pl_x / 128]))
			game->pl_y -= sin(game->cast->pa + M_PI_2) * 6;
	}
}

bool	ft_check_collision(char c)
{
	if (c == '1' || c == 'D')
		return (false);
	return (true);
}
