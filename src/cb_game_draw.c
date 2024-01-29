/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_game_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:43:27 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/29 23:41:44 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_draw_map(t_game *game, t_map *map)
{
	ft_draw_player(game, map->map);
	game->texture->wall_no = mlx_load_png(map->no);
	if (game->texture->wall_no == NULL)
		return (printf("Error\n'NO' Texture not loading\n"), 3);
	game->texture->wall_so = mlx_load_png(map->so);
	if (game->texture->wall_so == NULL)
		return (ft_destroy_img(game, 1),
			printf("Error\n'SO' Texture not loading\n"), 3);
	game->texture->wall_we = mlx_load_png(map->we);
	if (game->texture->wall_we == NULL)
		return (ft_destroy_img(game, 2),
			printf("Error\n'WE' Texture not loading\n"), 3);
	game->texture->wall_ea = mlx_load_png(map->ea);
	if (game->texture->wall_ea == NULL)
		return (ft_destroy_img(game, 3),
			printf("Error\n'EA' Texture not loading\n"), 3);
	if (ft_get_texture_size(game) == false)
		printf("Warning!\nTexture size too big\n");
	if (ft_get_add_tex(game) == 3) // LORENZO ICI POTO
		return (3);
	return (0);
}

void	ft_draw_player(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S' || map[i][j] == 'N')
			{
				game->pl_x = j * 128 + 20;
				game->pl_y = i * 128 + 20;
			}
			j++;
		}
		i++;
	}
}

bool	ft_get_texture_size(t_game *game)
{
	if (game->texture->wall_no->width > 64
		|| game->texture->wall_no->height > 64)
		return (ft_change_texture(game, 1), false);
	if (game->texture->wall_so->width > 64
		|| game->texture->wall_so->height > 64)
		return (ft_change_texture(game, 2), false);
	if (game->texture->wall_we->width > 64
		|| game->texture->wall_we->height > 64)
		return (ft_change_texture(game, 3), false);
	if (game->texture->wall_ea->width > 64
		|| game->texture->wall_ea->height > 64)
		return (ft_change_texture(game, 4), false);
	return (true);
}

void	ft_change_texture(t_game *game, int tex)
{
	if (tex == 1 && game->texture->wall_no->width > 64)
		game->texture->wall_no->width = 64;
	if (tex == 1 && game->texture->wall_no->height > 64)
		game->texture->wall_no->height = 64;
	if (tex == 2 && game->texture->wall_so->width > 64)
		game->texture->wall_so->width = 64;
	if (tex == 2 && game->texture->wall_so->height > 64)
		game->texture->wall_so->height = 64;
	if (tex == 3 && game->texture->wall_we->width > 64)
		game->texture->wall_we->width = 64;
	if (tex == 3 && game->texture->wall_we->height > 64)
		game->texture->wall_we->height = 64;
	if (tex == 4 && game->texture->wall_ea->width > 64)
		game->texture->wall_ea->width = 64;
	if (tex == 4 && game->texture->wall_ea->height > 64)
		game->texture->wall_ea->height = 64;
}
