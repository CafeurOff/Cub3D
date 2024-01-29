/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:34:26 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/29 22:56:00 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_game(t_map *map)
{
	map->game->dis_w = 1440;
	map->game->dis_h = 900;
	map->game->width = ft_get_longuest(map->map);
	map->game->height = ft_len_tab(map->map);
	ft_beggin(map->game, map);
}

int	ft_get_longuest(char **map)
{
	unsigned int	check;
	unsigned int	i;

	check = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (check < ft_strlen(map[i]))
			check = ft_strlen(map[i]);
		i++;
	}
	return (check);
}

void	ft_beggin(t_game *game, t_map *map)
{
	game->mlx = mlx_init(game->dis_w, game->dis_h, "Super Cub3D", true);
	ft_get_draw_texture(game, map);
	map->error = ft_draw_map(game, map);
	if (map->error > 0)
		return (mlx_terminate(game->mlx));
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(game->mlx, ft_hooks, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
