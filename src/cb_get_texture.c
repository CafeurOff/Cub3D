/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_get_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:37:23 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/29 23:44:44 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_get_draw_texture(t_game *game, t_map *map)
{
	game->ceiling = NULL;
	game->floor = NULL;
	ft_draw_ceiling(game, map);
	ft_draw_floor(game, map);
	game->background = mlx_new_image(game->mlx, game->dis_w, game->dis_h);
	ft_set_pixel(game->background, game->dis_w, game->dis_h, 0x0000000F);
	game->line = mlx_new_image(game->mlx, game->dis_w + 20, game->dis_h + 20);
}

void	ft_draw_ceiling(t_game *game, t_map *map)
{
	uint32_t	color;

	color = 0;
	if (SKY == 0)
	{
		game->ceiling = mlx_new_image(game->mlx,
				game->dis_w + 10, game->dis_h / 2 + 10);
		color = ft_rgb_hex(map->ceiling[0],
				map->ceiling[1], map->ceiling[2]);
		ft_set_pixel(game->ceiling, game->dis_w, game->dis_h / 2, color);
		mlx_image_to_window(game->mlx, game->ceiling, 0, 0);
		game->ceiling->instances[0].z = -1;
	}
}

void	ft_draw_floor(t_game *game, t_map *map)
{
	uint32_t	color;

	color = 0;
	if (FLOOR == 0)
	{
		game->floor = mlx_new_image(game->mlx,
				game->dis_w + 10, game->dis_h / 2 + 10);
		color = ft_rgb_hex(map->floor[0],
				map->floor[1], map->floor[2]);
		ft_set_pixel(game->floor, game->dis_w, game->dis_h / 2, color);
		mlx_image_to_window(game->mlx, game->floor, 0, game->dis_h / 2);
		game->floor->instances[0].z = -2;
	}
}

int	ft_get_add_tex(t_game *game)
{
	game->texture->door = mlx_load_png("./textures/wood_door.png");
	if (game->texture->door == NULL)
		return (ft_destroy_add(game, 2),
			printf("Door texture couldn't be opened\n"),
			ft_destroy_img(game, 4), 3);
	return (0);
}
