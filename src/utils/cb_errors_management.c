/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_errors_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <lduthill@42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:19:49 by lduthill          #+#    #+#             */
/*   Updated: 2024/02/06 14:01:16 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
		mlx_destroy_image(map->game->mlx, map->game->texture->wall_no->mlx_img);
		mlx_destroy_image(map->game->mlx, map->game->texture->wall_so->mlx_img);
		mlx_destroy_image(map->game->mlx, map->game->texture->wall_ea->mlx_img);
		mlx_destroy_image(map->game->mlx, map->game->texture->wall_we->mlx_img);
	}
	if (map->error == 0 || map->error == 3)
		free(map->game->texture);
	if (map->map != NULL)
		free(map->game);
	free(map);
}

void	ft_destroy_img(t_game *game, int i)
{
	if (i >= 1)
		mlx_destroy_image(game->mlx, game->texture->wall_no->mlx_img);
	if (i >= 2)
		mlx_destroy_image(game->mlx, game->texture->wall_so->mlx_img);
	if (i >= 3)
		mlx_destroy_image(game->mlx, game->texture->wall_we->mlx_img);
	if (i >= 4)
		mlx_destroy_image(game->mlx, game->texture->wall_ea->mlx_img);
}

void	ft_free_texture(t_map *map)
{
	mlx_destroy_window(map->game->mlx, map->game->win);
	mlx_destroy_image(map->game->mlx, map->game->texture->background->mlx_img);
	mlx_destroy_display(map->game->mlx);
	free(map->game->texture->wall_no);
	free(map->game->texture->wall_so);
	free(map->game->texture->wall_we);
	free(map->game->texture->wall_ea);
	free(map->game->texture->background);
	free(map->game->mlx);
	ft_endgame(map);
	exit(0);
}

int	ft_exit(t_map *map)
{
	ft_destroy_img(map->game, 4);
	mlx_destroy_window(map->game->mlx, map->game->win);
	mlx_destroy_image(map->game->mlx, map->game->texture->background->mlx_img);
	mlx_destroy_display(map->game->mlx);
	free(map->game->mlx);
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
	free(map->game->texture->wall_no);
	free(map->game->texture->wall_so);
	free(map->game->texture->wall_we);
	free(map->game->texture->wall_ea);
	free(map->game->texture->background);
	free(map->game->texture);
	free(map->game);
	free(map);
	exit(0);
}
