/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfroidev <sfroidev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:57:25 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/05 15:33:12 by sfroidev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_hooks(t_map *map)
{
	//ft_on_exit(game);
	ft_set_pixel(map->game->texture->background, WIDTH, HEIGHT, map);
	ft_raycaster(map->game);
	mlx_put_image_to_window(map->game->mlx, map->game->win, map->game->texture->background->mlx_img, 0, 0);
	return (0);
}

/*

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


*/
