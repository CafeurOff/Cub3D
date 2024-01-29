/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_errors_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:19:49 by lduthill          #+#    #+#             */
/*   Updated: 2024/01/29 23:46:09 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab && tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}

void	ft_endgame(t_map *map)
{
	if (map->no)
		free(map->no);
	if (map->ea)
		free(map->ea);
	if (map->we)
		free(map->we);
	if (map->so)
		free(map->so);
	if (map->error != 2)
		close(map->fd);
	if (map->map != NULL)
	{
		free_tab(map->map);
		free(map->game->ray);
		free(map->game->cast);
		free(map->game->dl);
	}
	ft_free_struct(map);
}

void	ft_free_struct(t_map *map)
{
	if (map->error == 0)
	{
		if (SKY == 1)
			mlx_delete_texture(map->game->texture->ceiling);
		if (FLOOR == 1)
			mlx_delete_texture(map->game->texture->floor);
		mlx_delete_texture(map->game->texture->wall_no);
		mlx_delete_texture(map->game->texture->wall_so);
		mlx_delete_texture(map->game->texture->wall_ea);
		mlx_delete_texture(map->game->texture->wall_we);
	}
	if (map->error == 0 || map->error == 3)
		free(map->game->texture);
	if (map->map != NULL)
		free(map->game);
	free(map);
}

void	ft_destroy_img(t_game *game, int i)
{
	if (i == 1)
		mlx_delete_texture(game->texture->wall_no);
	if (i == 2)
	{
		mlx_delete_texture(game->texture->wall_no);
		mlx_delete_texture(game->texture->wall_so);
	}
	if (i == 3)
	{
		mlx_delete_texture(game->texture->wall_no);
		mlx_delete_texture(game->texture->wall_so);
		mlx_delete_texture(game->texture->wall_we);
	}
	if (i == 4)
	{
		mlx_delete_texture(game->texture->wall_no);
		mlx_delete_texture(game->texture->wall_so);
		mlx_delete_texture(game->texture->wall_we);
		mlx_delete_texture(game->texture->wall_ea);
	}
}

void	ft_destroy_add(t_game *g, int i)
{
	if (i >= 1 && FLOOR == 1)
		mlx_delete_texture(g->texture->floor);
	if (i >= 2 && SKY == 1)
		mlx_delete_texture(g->texture->ceiling);
	if (i >= 3)
		mlx_delete_texture(g->texture->door);
}
